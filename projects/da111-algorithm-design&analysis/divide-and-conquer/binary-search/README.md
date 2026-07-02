# Binary Search (Divide & Conquer)

## What it does
Finds an element in a SORTED array super fast. Instead of checking every single item one by one, we split the array and throw away half each time. Way better than linear search!

## How D&C works for binary search

### Divide
Cut the array in half. Look at the middle element — is our target smaller or bigger? That instantly tells us which half to keep and which to toss.

### Conquer
Recursively search only the half that could contain the target. Keep halving until we find it OR there's nothing left.

### Combine
Just return the index. Nothing fancy here, just finding the thing.

## Time complexity
```
T(n) = T(n/2) + O(1)
```
Each step cuts work in half and only does constant checks per level → **O(log n)**

For 1 million items? Only ~20 comparisons. Linear search would need all 1 million 😱

## Important stuff
- Array must be **sorted** first or it won't work (that's why the main() sorts it before testing)
- Only works on random-access data like arrays
- Not useful for unsorted data — use linear search instead

## Compile & run

```bash
gcc binary_search.c -o binary_search
./binary_search
```

---

**Course:** DA110 Data Structures  
**Author:** Miodrag Simic
