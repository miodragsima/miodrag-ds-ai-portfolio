# Quick Sort (Divide & Conquer)

## What it does
Sorts an array by picking a pivot element, splitting everything around it into two pieces: smaller on the left, larger on the right. Then repeat for each piece recursively. Super popular in real codebases!

## How D&C works for quicksort

### Divide (Partition step)
Pick a pivot (we just use the last element for simplicity). Move all elements smaller than pivot to the left, all bigger to the right. The pivot lands exactly where it belongs in the sorted array — that's its final position.

### Conquer (Recursive sort)
Now we have two sub-problems: sort the left side and sort the right side. Each is a smaller version of the original problem. Just call quicksort again.

### Combine
No merging needed! Since we partitioned in-place, everything just falls into place automatically. That's actually kind of brilliant 😅

## Time complexity
| Case | Complexity | What it means |
|------|-----------|---------------|
| Best | O(n log n) | Balanced splits every time |
| Average | O(n log n) | Normal case, happens most often |
| Worst | O(n²) | Pivot always worst choice → sorted/reverse-sorted array |

The recurrence is:
```
T(n) = T(k) + T(n-k-1) + O(n)  ← partition costs O(n)
```

On average the split is somewhat balanced, so amortized it's **O(n log n)** again.

## Why use it?
- Super fast in practice — constant factor is tiny (no extra arrays like merge sort!)
- Sorts in-place → uses very little extra memory (just recursion stack)
- Used by default in most standard libraries (`std::sort` in C++, `Arrays.sort` in Java)

## Downside
- Worst case O(n²) — but you can randomize the pivot to avoid it in practice
- Not a stable sort (elements with equal values may swap order)

## Compile & run

```bash
gcc quick_sort.c -o quick_sort
./quick_sort
```

---

**Course:** DA110 Data Structures  
**Author:** Miodrag Simic
