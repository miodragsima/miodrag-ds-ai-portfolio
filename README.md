# miodrag-ds-ai-portfolio

Selected Data Science & AI labs, projects, and solutions from my BSc studies

## Miodrag DS & AI Portfolio

This repository contains a curated selection of my work from my BSc studies in Data Science & Artificial Intelligence. It showcases coding labs, practical implementations, and key concepts I have studied and applied.

---

### About

I am a BSc student focusing on Data Science and Artificial Intelligence. This repository highlights my hands-on experience with:

- Data analysis
- Machine learning fundamentals  
- Neural networks
- Algorithmic problem solving
- Practical coding exercises

---

## Repository Structure

```text
miodrag-ds-ai-portfolio/
├── projects/
│   ├── da110-data-structures/          # Data Structures (C)
│   │   ├── arrays/                      # Arrays implementation
│   │   ├── linked-lists/                # Singly Linked Lists
│   │   ├── stacks/                      # Stack data structure
│   │   ├── queues/                      # Queue & Circular Queue
│   │   ├── trees/                       # Binary Tree (traversals)
│   │   ├── sorting/                     # Bubble, Selection, Insertion Sort
│   │   └── searching/                   # Linear & Binary Search
│   ├── da111-algorithm-design&analysis/ # Algorithms (C)
│   │   ├── divide-and-conquer/          # Merge Sort, Quick Sort, Binary Search
│   │   └── dynamic-programming/         # Fibonacci, Knapsack, LCS, Coin Change
│   ├── eda-titanic-analysis/            # Titanic EDA (Python/pandas/seaborn)
│   └── eda-titanic-dashboard/           # Interactive Dashboard (Streamlit/Plotly)
├── README.md
├── .gitignore
└── LICENSE
```

---

## Projects Overview

### 1. Data Structures & Algorithms Portfolio (`da110-data-structures`)
Fundamental data structures implemented in C: Arrays, Linked Lists, Stacks, Queues, Trees, Sorting (Bubble, Selection, Insertion), Searching (Linear, Binary).

**Language:** C | **Difficulty:** Beginner → Intermediate

### 2. Algorithm Design & Analysis (`da111-algorithm-design`)
- **Divide & Conquer:** Merge Sort, Quick Sort, Binary Search — O(n log n), O(log n)
- **Dynamic Programming:** Fibonacci (memoized), 0/1 Knapsack, Longest Common Subsequence, Coin Change Problem

**Language:** C | **Difficulty:** Intermediate

### 3. Titanic EDA (`eda-titanic-analysis`)
Deep dive into the Titanic dataset using pandas and seaborn: survival rate by class/gender, age distribution, fare analysis, missing data heatmap, correlation matrix.

**Language:** Python | **Libraries:** pandas, matplotlib, seaborn | **Difficulty:** Intermediate

### 4. Titanic Dashboard (`eda-titanic-dashboard`)
Interactive Streamlit/Plotly dashboard with real-time filters (class, gender, age range, embarkation port), dynamic charts, KPI cards, and CSV export.

**Language:** Python | **Libraries:** streamlit, plotly | **Difficulty:** Intermediate → Advanced

---

## How to Run Each Project

### Data Structures (C)
```bash
cd projects/da110-data-structures/arrays && gcc main.c -o demo && ./demo
```

### Dynamic Programming (C)
```bash
cd projects/da111-algorithm-design&analysis/dynamic-programming
gcc fibonacci.c -o fib && ./fib
```

### Titanic EDA (Python)
```bash
cd projects/eda-titanic-analysis && pip install pandas matplotlib seaborn numpy
python eda_titanic.py
```

### Titanic Dashboard (Streamlit)
```bash
cd projects/eda-titanic-dashboard && pip install streamlit plotly pandas numpy seaborn
streamlit run dashboard_titanic.py
```

---

## Skills & Technologies

| Category | Technologies |
|----------|-------------|
| Languages | C, Python |
| Data Science | pandas, matplotlib, seaborn, plotly |
| Web/App | Streamlit |
| Algorithms | Divide & Conquer, Dynamic Programming |
| Data Structures | Arrays, Linked Lists, Stacks, Queues, Trees |

---

## Future Work

- [ ] Machine Learning projects (scikit-learn)
- [ ] Deep Learning project (TensorFlow/PyTorch)
- [ ] NLP/Sentiment Analysis project
- [ ] Personal website / landing page
