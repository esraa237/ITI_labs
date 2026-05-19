### GitHub Copilot

The `quickSort` function is a recursive implementation of the QuickSort algorithm, which efficiently sorts arrays. Here’s how it works:

1. **Input Validation:**
   It first checks if the input is an array. If not, it throws a `TypeError`.
2. **Base Case:**
   If the array has 0 or 1 element, it is already sorted, so the function returns it as is.
3. **Pivot Selection:**
   The function selects the last element of the array as the pivot.
4. **Partitioning:**
   It creates two new arrays:
   * `left`: contains elements less than the pivot.
   * `right`: contains elements greater than or equal to the pivot.
5. **Recursion:**
   The function recursively sorts the `left` and `right` arrays.
6. **Combining Results:**
   It returns a new array by concatenating the sorted `left` array, the pivot, and the sorted `right` array.

This process continues recursively, breaking the array into smaller pieces, until the entire array is sorted. QuickSort is efficient for large datasets and has an average time complexity of O(n log n).
