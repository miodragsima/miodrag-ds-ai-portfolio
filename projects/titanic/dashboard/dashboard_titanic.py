import streamlit as st
import pandas as pd
import plotly.express as px

# ==================================================
# CONFIG
# ==================================================

st.set_page_config(
    page_title="Titanic Explorer",
    page_icon="🚢",
    layout="wide"
)

st.title("🚢 Titanic Explorer")
st.markdown("*Interactive dashboard for exploring the Titanic dataset*")

# ==================================================
# DATA
# ==================================================

@st.cache_data
def load_data():
    df = pd.read_csv("titanic.csv")

    embark_map = {
        "S": "Southampton",
        "C": "Cherbourg",
        "Q": "Queenstown"
    }

    df["EmbarkedName"] = df["Embarked"].map(embark_map)

    return df

df = load_data()

# ==================================================
# SIDEBAR FILTERS
# ==================================================

with st.sidebar:
    st.header("Filters")

    pclass = st.selectbox(
        "Passenger Class",
        ["All"] + [str(x) for x in sorted(df["Pclass"].unique())]
    )

    sex = st.selectbox(
        "Gender",
        ["All"] + sorted(df["Sex"].dropna().unique())
    )

    min_age = int(df["Age"].dropna().min())
    max_age = int(df["Age"].dropna().max())

    age_range = st.slider(
        "Age Range",
        min_age,
        max_age,
        (min_age, max_age)
    )

    embark = st.selectbox(
        "Embarkation Port",
        ["All"] + sorted(df["EmbarkedName"].dropna().unique())
    )

# ==================================================
# FILTERING
# ==================================================

filtered = df.copy()

if pclass != "All":
    filtered = filtered[filtered["Pclass"] == int(pclass)]

if sex != "All":
    filtered = filtered[filtered["Sex"] == sex]

# Altersfilter nur auf vorhandene Alterswerte anwenden
filtered = filtered[
    filtered["Age"].isna()
    | (
        (filtered["Age"] >= age_range[0])
        & (filtered["Age"] <= age_range[1])
    )
]

if embark != "All":
    filtered = filtered[filtered["EmbarkedName"] == embark]

# ==================================================
# EMPTY CHECK
# ==================================================

if filtered.empty:
    st.warning("No passengers match the selected filters.")
    st.stop()

# ==================================================
# KPIs
# ==================================================

st.header("Summary Statistics")

c1, c2, c3, c4 = st.columns(4)

with c1:
    st.metric("Passengers", len(filtered))

with c2:
    st.metric(
        "Survival Rate",
        f"{filtered['Survived'].mean():.1%}"
    )

with c3:
    st.metric(
        "Average Fare",
        f"${filtered['Fare'].mean():.2f}"
    )

with c4:
    st.metric(
        "Average Age",
        f"{filtered['Age'].mean():.1f} yrs"
        if filtered["Age"].notna().any()
        else "N/A"
    )

# ==================================================
# VISUALIZATIONS
# ==================================================

st.header("Visualizations")

tab1, tab2, tab3, tab4, tab5 = st.tabs([
    "Survival by Class",
    "Survival by Gender",
    "Age Distribution",
    "Fare vs Age",
    "Passenger Distribution"
])

# --------------------------------------------------
# SURVIVAL BY CLASS
# --------------------------------------------------

with tab1:

    class_stats = (
        filtered.groupby("Pclass")["Survived"]
        .agg(["mean", "count"])
        .reset_index()
    )

    class_stats.columns = [
        "Pclass",
        "SurvivalRate",
        "Passengers"
    ]

    class_stats["SurvivalRate"] *= 100

    fig = px.bar(
        class_stats,
        x="Pclass",
        y="SurvivalRate",
        color="Pclass",
        title="Survival Rate by Passenger Class",
        hover_data=["Passengers"]
    )

    st.plotly_chart(fig, use_container_width=True)

# --------------------------------------------------
# SURVIVAL BY GENDER
# --------------------------------------------------

with tab2:

    gender_stats = (
        filtered.groupby("Sex")["Survived"]
        .mean()
        .reset_index()
    )

    gender_stats["Survived"] *= 100

    fig = px.bar(
        gender_stats,
        x="Sex",
        y="Survived",
        color="Sex",
        title="Survival Rate by Gender"
    )

    st.plotly_chart(fig, use_container_width=True)

# --------------------------------------------------
# AGE DISTRIBUTION
# --------------------------------------------------

with tab3:

    fig = px.histogram(
        filtered[filtered["Age"].notna()],
        x="Age",
        color="Survived",
        barmode="overlay",
        opacity=0.7,
        title="Age Distribution: Survived vs Died"
    )

    st.plotly_chart(fig, use_container_width=True)

# --------------------------------------------------
# FARE VS AGE
# --------------------------------------------------

with tab4:

    valid = filtered[
        filtered["Age"].notna()
        & filtered["Fare"].notna()
    ]

    fig = px.scatter(
        valid,
        x="Age",
        y="Fare",
        color="Pclass",
        symbol="Survived",
        hover_data=["Name", "Sex"],
        title="Fare vs Age"
    )

    st.plotly_chart(fig, use_container_width=True)

# --------------------------------------------------
# PASSENGER DISTRIBUTION
# --------------------------------------------------

with tab5:

    class_dist = (
        filtered["Pclass"]
        .value_counts()
        .sort_index()
        .reset_index()
    )

    class_dist.columns = ["Pclass", "Passengers"]

    fig = px.pie(
        class_dist,
        values="Passengers",
        names="Pclass",
        title="Passenger Distribution by Class"
    )

    st.plotly_chart(fig, use_container_width=True)

# ==================================================
# RAW DATA
# ==================================================

st.header("Data")

with st.expander("Show Raw Data"):

    st.dataframe(
        filtered.reset_index(drop=True),
        use_container_width=True
    )

    csv = filtered.to_csv(index=False).encode("utf-8")

    st.download_button(
        "Download Filtered CSV",
        data=csv,
        file_name="titanic_filtered.csv",
        mime="text/csv"
    )

# ==================================================
# DATA QUALITY INFO
# ==================================================

missing_age = df["Age"].isna().sum()

st.caption(
    f"Dataset contains {missing_age} passengers with unknown age. "
    "These passengers remain included unless another filter removes them."
)