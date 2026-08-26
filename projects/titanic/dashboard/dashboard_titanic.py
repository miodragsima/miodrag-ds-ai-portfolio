import streamlit as st
import pandas as pd
import plotly.express as px

st.title("Titanic Explorer - Interactive Dashboard")
st.markdown("*An interactive dashboard for exploring the Titanic dataset.*")

@st.cache_data
def load_data():
    url = 'https://raw.githubusercontent.com/datasciencehandbook/notebooks/data/titanic.csv'
    return pd.read_csv(url)

df = load_data()

with st.sidebar:
    st.header("Filters")
    pc = st.selectbox('Passenger Class', ['All'] + [str(i) for i in range(1,4)])
    sex = st.selectbox('Gender', ['All'] + list(df['Sex'].unique()))
    min_age, max_age = df['Age'].dropna().min(), df['Age'].dropna().max()
    age_range = st.slider('Age Range (years)', int(min_age), int(max_age), (int(min_age), int(max_age)))
    emb = st.selectbox('Embarkation Port', ['All'] + list(df['Embarked'].unique()))

filtered = df.copy()
if pc != 'All': filtered = filtered[filtered['Pclass'] == int(pc)]
if sex != 'All': filtered = filtered[filtered['Sex'] == sex]
filtered = filtered[(filtered['Age'] >= age_range[0]) & (filtered['Age'] <= age_range[1])]
if emb != 'All': filtered = filtered[filtered['Embarked'] == emb]

st.header("Summary Statistics")
c1, c2, c3, c4 = st.columns(4)
with c1: st.metric('Passengers', len(filtered))
with c2: st.metric('Survival Rate', f'{filtered["Survived"].mean():.1%}')
with c3: st.metric('Avg Fare ($)', f'${filtered["Fare"].mean():.0f}')
with c4: st.metric('Avg Age (yrs)', f'{filtered["Age"].dropna().mean():.0f}')

st.header("Visualizations")
t1, t2, t3 = st.tabs(['Survival by Class', 'Age Distribution', 'Fare vs Age'])
with t1:
    s = filtered.groupby('Pclass')['Survived'].agg(['mean','count']).rename(columns={'mean':'rate','count':'pax'})
    s['rate'] = (s['rate']*100).round(1)
    f1 = px.bar(s.reset_index(), x='Pclass', y='rate', title='Survival Rate (%)', color='Pclass', color_discrete_sequence=['#e74c3c','#f39c12','#2ecc71'])
    st.plotly_chart(f1, use_container_width=True)
with t2:
    f2 = px.histogram(filtered[filtered['Age'].notna()], x='Age', color='Survived', barmode='overlay', opacity=0.7, title='Age - Survived vs Died')
    st.plotly_chart(f2, use_container_width=True)
with t3:
    valid = filtered[filtered['Fare'].notna()]
    f3 = px.scatter(valid, x='Age', y='Fare', color='Survived', size='Fare', opacity=0.7, title='Fare vs Age', labels={'Age':'Age (years)', 'Fare': 'Fare ($)'})
    st.plotly_chart(f3, use_container_width=True)

with st.expander('Raw Data', expanded=False):
    st.dataframe(filtered.reset_index(drop=True), use_container_width=True)
    csv = filtered.to_csv(index=False).encode('utf-8')
    st.download_button('Download CSV', data=csv, file_name='titanic_filtered.csv', mime='text/csv')
