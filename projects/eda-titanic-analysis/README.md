# Exploratory Data Analysis — Titanic Dataset

## Overview
Exploratory analysis of the famous Titanic dataset to understand which factors influenced passenger survival. Uses `pandas`, `matplotlib` and `seaborn`.

## Key Questions Answered
- Which class (Pclass) had the highest survival rate?
- How did gender affect survival (the "women & children first" principle)?
- Did age play a role — were younger passengers more likely to survive?
- Were there cultural patterns in ticket classes vs. embarkation ports?

## Tools & Libraries Used
| Tool/Library | Purpose |
|---|---|
| pandas | Data loading, cleaning, manipulation |
| matplotlib / seaborn | Statistical visualizations |

## How to Run
```bash
pip install pandas matplotlib seaborn numpy
python eda_titanic.py
```

## Visualizations Included
- Survival distribution by gender and class
- Age distribution of survivors vs. non-survivors
- Fare price analysis by passenger class
- Embarkation port & ticket fare correlation
- Missing data heatmap (Cabin, Age)
