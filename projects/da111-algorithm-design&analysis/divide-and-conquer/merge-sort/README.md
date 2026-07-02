# Merge Sort (Divide & Conquer)

## How it works

### Step 1 — Divide
Split the array in half until each piece only has ONE element.  
One element is already sorted, right? 😂

### Step 2 — Conquer
Sort each half recursively. Keep dividing until base case = single element.

### Step 3 — Combine (Merge step)
Now glue everything back together by merging two sorted halves into one sorted piece.  
Take the smaller element first, move to next — that's it.

## Time complexity: O(n log n)
- Divide: `log n` levels deep (each split cuts array in half)
- Merge at each level: `O(n)` work total across all merges on same level
- Total = `n × log n` → **O(n log n)** — fast!

## Why use it?
- Guaranteed O(n log n), even worst case (unlike quicksort)
- Stable sort (doesn't mess up order of equal elements)
- Great for linked lists too (no extra space needed like arrays)

## Downside
- Uses extra memory for the temp arrays during merge
- Can be a bit slower in practice than quicksort because of overhead

## Compile & run

```bash
gcc merge_sort.c -o merge_sort
./merge_sort
```

---

**Course:** DA110 Data Structures  
**Author:** Miodrag Simic
