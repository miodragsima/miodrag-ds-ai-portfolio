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

## 🚀 How to Run

1. **EDA**: Open `titanic/eda/titanic_eda.ipynb` in Jupyter Notebook / VS Code
2. **Dashboard**: Run `streamlit run titanic/dashboard/dashboard_titanic.py` (or view notebook)
3. **ML Pipeline**: Run `titanic/ml-pipeline/titanic_kaggle_ml.ipynb`

## 📊 What's Inside?

- **Data Cleaning & Preprocessing**: Missing value imputation, title extraction, cabin deck mapping, family size encoding
- **Feature Engineering**: One-hot encoding, age binning, correlation analysis
- **Model Comparison**: Logistic Regression, Random Forest, Gradient Boosting, SVM (RBF) with cross-validation
- **Hyperparameter Tuning**: GridSearchCV for optimal parameters
- **Evaluation**: Confusion matrix, classification report, feature importance visualization
- **Kaggle Ready**: `titanic_predictions.csv` formatted for direct submission

## 📅 Timeline

- **25. November 2026 (14:17)**: Data analysis & dashboard development
- **27. November 2026 (15:33)**: ML pipeline, feature engineering, model tuning

---
*Created as part of the Data Science & AI Portfolio Project*
