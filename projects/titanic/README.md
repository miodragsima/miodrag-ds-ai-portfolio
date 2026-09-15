# Titanic: End-to-End Data Science & Machine Learning Project

A complete data science workflow from exploratory analysis to machine learning deployment, built in Jupyter notebooks.

## 📂 Project Structure

```
titanic/
├── eda/                    # Exploratory Data Analysis
│   ├── titanic_eda.ipynb   # Interactive EDA with pandas/seaborn & 6 chapters
│   └── eda_titanic.py      # Standalone Python script version of the analysis
│
├── dashboard/              # Interactive Visualization Dashboard
│   ├── titanic_dashboard.ipynb  # Streamlit/Plotly dashboard guide
│   └── dashboard_titanic.py       # Standalone Python code for the dashboard
│
└── ml-pipeline/            # Machine Learning Pipeline (Kaggle Style)
    ├── titanic_kaggle_ml.ipynb  # Full ML pipeline: preprocessing → feature engineering → model comparison → tuning
    └── titanic_predictions.csv  # Kaggle submission format predictions
```

## 🚀 Quick Start

### Prerequisites

- Python 3.8+
- `pip` or `conda` for package management

### Installation & Usage

```bash
# Clone the repository
git clone https://github.com/miodragsima/miodrag-ds-ai-portfolio.git
cd miodrag-ds-ai-portfolio/projects/titanic

# Install dependencies
pip install pandas numpy matplotlib seaborn plotly streamlit scikit-learn jupyter

# Run EDA
jupyter notebook eda/titanic_eda.ipynb
# or
python eda/eda_titanic.py

# Run Dashboard (Streamlit)
streamlit run dashboard/dashboard_titanic.py

# Run ML Pipeline
jupyter notebook ml-pipeline/titanic_kaggle_ml.ipynb
```

## 📊 What's Inside?

This project covers the **complete data science lifecycle**:

### 1. Exploratory Data Analysis (EDA)
- **Data Cleaning:** Handling missing values, duplicate check, type conversion
- **Feature Engineering:** Title extraction from names, cabin deck mapping, family size encoding, age binning
- **Statistical Analysis:** Descriptive statistics, correlation matrix, hypothesis testing
- **Visualizations:**
  - Survival rate by passenger class, gender, embarkation port
  - Age distribution of survivors vs. non-survivors
  - Fare analysis across classes
  - Missing data heatmap and patterns
  - Pairwise feature correlations

### 2. Interactive Dashboard (Streamlit + Plotly)
- **Real-time Filters:** Passenger class, gender, age range, embarkation port
- **KPI Cards:** Total passengers, survival rate, average fare, average age
- **Interactive Charts:**
  - Survival rate by class (bar chart)
  - Survival rate by gender (bar chart)
  - Age distribution with overlay (histogram)
  - Fare vs. Age scatter plot colored by class
  - Passenger distribution by class (pie chart)
- **Raw Data Viewer:** Expandable table with CSV export

### 3. Machine Learning Pipeline
- **Preprocessing:** Missing value imputation, outlier handling, encoding categorical variables
- **Feature Engineering:** One-hot encoding, interaction features, polynomial features where applicable
- **Model Comparison:**
  - Logistic Regression
  - Random Forest Classifier
  - Gradient Boosting (XGBoost-compatible)
  - Support Vector Machine (RBF kernel)
- **Hyperparameter Tuning:** `GridSearchCV` for optimal parameters per model
- **Evaluation Metrics:** Accuracy, Precision, Recall, F1-Score, ROC-AUC
- **Visualizations:** Confusion matrix, classification report, feature importance plots

## 🎯 Results & Insights

### Key Findings from EDA

| Insight | Description |
|---------|-------------|
| **Class Bias** | Higher passenger class strongly correlates with survival (1st > 2nd > 3rd) |
| **Gender Gap** | Female passengers had significantly higher survival rates than male passengers |
| **Age Factor** | Children had better survival rates; elderly showed varied outcomes |
| **Fare Impact** | Higher fares generally linked to higher survival, but class is a stronger predictor |

### Model Performance (Expected)

| Model | Expected Accuracy Range | Notes |
|-------|------------------------|-------|
| Logistic Regression | 78–82% | Baseline model, interpretable |
| Random Forest | 81–85% | Handles non-linear relationships well |
| Gradient Boosting | 83–87% | Often the top performer in tabular data |
| SVM (RBF) | 79–83% | Sensitive to scaling and outliers |

> **Note:** Exact results may vary based on train/test split, random seed, and preprocessing choices. The `titanic_predictions.csv` contains your Kaggle-ready submissions.

## 🛠️ Technologies & Libraries

| Category | Tools |
|----------|-------|
| **Languages** | Python 3 |
| **Data Manipulation** | pandas, numpy |
| **Visualization** | matplotlib, seaborn, plotly, streamlit |
| **Machine Learning** | scikit-learn |
| **Environment** | Jupyter Notebook, VS Code |

## 📈 Future Enhancements

- [ ] Deploy Streamlit dashboard to Streamlit Cloud / Hugging Face Spaces
- [ ] Add SHAP/LIME for model interpretability
- [ ] Implement cross-validation strategy with stratified splits
- [ ] Experiment with deep learning (MLP, simple neural net)
- [ ] Compare with top Kaggle solutions (feature stacking, blending)

## 📝 Notes

- The dataset (`titanic.csv`) is expected to be in the project root. You can download it from [Kaggle](https://www.kaggle.com/c/titanic/data).
- All notebooks are self-contained and include cell-by-cell explanations.
- The dashboard supports real-time filtering with instant chart updates.

---

*Created as part of the Data Science & AI Portfolio Project*
