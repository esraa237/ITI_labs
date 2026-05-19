### GitHub Copilot

Here’s a comparison of QuickSort with other common sorting algorithms:

| Algorithm               | Time Complexity (Average/Worst) | Space Complexity | Stable | Notes                                                               |
| ----------------------- | ------------------------------- | ---------------- | ------ | ------------------------------------------------------------------- |
| **QuickSort**     | O(n log n) / O(n²)             | O(log n)         | No     | Very fast in practice; not stable; worst case rare with good pivots |
| **MergeSort**     | O(n log n) / O(n log n)         | O(n)             | Yes    | Consistent performance; stable; uses extra memory                   |
| **HeapSort**      | O(n log n) / O(n log n)         | O(1)             | No     | Good worst-case; not stable; less cache-friendly                    |
| **BubbleSort**    | O(n²) / O(n²)                 | O(1)             | Yes    | Simple but slow; rarely used for large datasets                     |
| **InsertionSort** | O(n²) / O(n²)                 | O(1)             | Yes    | Efficient for small or nearly sorted arrays; stable                 |
| **SelectionSort** | O(n²) / O(n²)                 | O(1)             | No     | Simple but inefficient; not stable                                  |

**Summary:**

* **QuickSort** is usually the fastest for large, unsorted arrays but is not stable.
* **MergeSort** is stable and has predictable performance, but uses more memory.
* **HeapSort** is memory efficient but not stable and can be slower than QuickSort.
* **BubbleSort, InsertionSort, and SelectionSort** are simple but inefficient for large datasets.

**When to use:**

* Use **QuickSort** for general-purpose sorting when stability is not required.
* Use **MergeSort** when you need a stable sort or are working with linked lists.
* Use **InsertionSort** for small or nearly sorted arrays.
