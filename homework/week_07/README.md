# Merge Sort

## 1. Problem

Implement **Merge Sort** to sort an array of `n` integers in ascending order.

- **Input:** An integer `n`, followed by `n` integers.
- **Output:** The sorted array in ascending order.

## 2. Understanding the Algorithm

The main idea of Merge Sort is to use **divide and conquer**.

Unlike Selection Sort and Insertion Sort, which gradually build a sorted part of the array, Merge Sort divides the array into smaller segments until each segment contains only one element. It then merges these segments back together in sorted order.

The algorithm has three main steps:

- **Divide:** Split the current array segment into two halves.
- **Conquer:** Recursively sort the left and right halves.
- **Merge:** Combine the two sorted halves into one sorted segment.

For example:

```text
101 23 57 13
```

First, divide the array into two halves:

```text
101 23 | 57 13
```

Continue dividing:

```text
101 | 23 | 57 | 13
```

Each segment now contains one element, so it is already sorted.

Next, merge adjacent segments in ascending order:

```text
23 101 | 13 57
```

Then merge the two sorted halves:

```text
13 23 57 101
```

Therefore, the array is sorted by repeatedly dividing it into smaller segments and merging them back together.

## 3. Implementation

The implementation is organized into four functions:

```cpp
void print_arr (int arr[], int left, int right);

void merge_sort (int arr[], int length);

void merge_sort_recursive (int arr[], int left, int right);

void merge_sorted_array (int arr[], int left, int middle, int right);
```

### `merge_sort()`

This is the entry point of the algorithm. It calls the recursive function with the boundaries of the entire array.

```cpp
void merge_sort (int arr[], int length){
    merge_sort_recursive (arr, 0, length - 1);
}
```

### `merge_sort_recursive()`

This function divides the array segment into two halves and recursively sorts each half.

```cpp
void merge_sort_recursive (int arr[], int left, int right){
    if (left < right) {
        int middle = (right + left) / 2;

        merge_sort_recursive (arr, left, middle);
        merge_sort_recursive (arr, middle + 1, right);

        merge_sorted_array (arr, left, middle, right);
    }
}
```

Here:

- `left` is the index of the first element in the current segment.
- `right` is the index of the last element in the current segment.
- `middle` divides the segment into two halves.
- `if (left < right)` ensures that recursion stops when a segment contains only one element.

An important point is that the division phase does not physically create new subarrays. Instead, the algorithm uses index boundaries to represent smaller segments of the original array.

### `merge_sorted_array()`

This function merges two sorted segments into one sorted segment.

The two segments are:

- Left segment: `arr[left..middle]`
- Right segment: `arr[middle + 1..right]`

Temporary arrays store the elements from both segments before they are merged back into the original array.

The algorithm compares the current elements from the two temporary arrays and places the smaller one into the original array.

This process continues until every element has been copied back in ascending order.

### `print_arr()`

This function prints a specific segment of the array using the `left` and `right` indices.

It is useful for observing the intermediate `Divide` and `Merge` steps during execution.

## 4. Complexity

At each level of recursion, the algorithm processes all `n` elements during merging.

The array is divided approximately in half at each level, giving about `log₂(n)` levels of recursion.

Therefore:

- **Best case:** `O(n log n)`
- **Average case:** `O(n log n)`
- **Worst case:** `O(n log n)`

The auxiliary space complexity is **`O(n)`** because temporary arrays are used during merging.

Unlike Selection Sort, Merge Sort maintains its `O(n log n)` time complexity regardless of the initial order of the array.

---

## Test Cases

### Test case 1 – One element

**Input**

```text
1
7
```

**Output**

```text
7
```

### Test case 2 – Reverse sorted

**Input**

```text
5
5 4 3 2 1
```

**Output**

```text
1 2 3 4 5
```

### Test case 3 – Duplicate and negative values

**Input**

```text
6
3 -1 2 3 0 -1
```

**Output**

```text
-1 -1 0 2 3 3
```

### Test case 4 – Already sorted

**Input**

```text
5
1 2 3 4 5
```

**Output**

```text
1 2 3 4 5
```

---

## Concepts Practiced

- Divide-and-conquer algorithms
- Recursive function calls and base cases
- Array indexing and subarray boundaries
- Merging two sorted sequences
- Temporary arrays
- Time and auxiliary space complexity analysis

---

