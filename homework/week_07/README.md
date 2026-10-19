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

# Quick Sort

## 1. Problem

Implement **Quick Sort** to sort an array of `n` integers in ascending order.

- **Input:** An integer `n`, followed by `n` integers.
- **Output:** The sorted array in ascending order.

## 2. Understanding the Algorithm

The main idea of Quick Sort is to use **divide and conquer**.

Unlike Merge Sort, which divides the array into two halves and merges them afterward, Quick Sort rearranges the elements around a selected element called the **pivot**.

The algorithm has three main steps:

- **Choose a pivot:** Select an element from the current array segment.
- **Partition:** Rearrange the elements so that those less than or equal to the pivot are placed on its left, while those greater than the pivot are placed on its right.
- **Conquer:** Recursively sort the segments on the left and right of the pivot.

For example:

```text
3 1 4 2 5
```

Choose the first element, `3`, as the pivot:

```text
Pivot = 3
```

After partitioning, the elements are rearranged so that the pivot is in its correct position:

```text
2 1 3 4 5
```

The pivot `3` is now at index `2`. All elements to its left are less than or equal to `3`, while all elements to its right are greater than `3`.

Next, recursively sort the two segments:

```text
2 1 | 3 | 4 5
```

After sorting the left and right segments:

```text
1 2 | 3 | 4 5
```

The final sorted array is:

```text
1 2 3 4 5
```

Therefore, Quick Sort sorts an array by repeatedly partitioning it around a pivot and recursively sorting the resulting segments.

## 3. Implementation

The implementation is organized into four functions:

```cpp
void swap (int *x, int *y);

void quick_sort (int arr[], int length);

void quick_sort_recursive (int arr[], int left, int right);

int partition (int arr[], int left, int right);
```

### `swap()`

This function exchanges the values stored at two memory addresses.

```cpp
void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
```

It is used during partitioning to rearrange elements in the array.

### `quick_sort()`

This is the entry point of the algorithm. It calls the recursive function with the boundaries of the entire array.

```cpp
void quick_sort (int arr[], int length){
    quick_sort_recursive (arr, 0, length - 1);
}
```

The initial segment extends from index `0` to index `length - 1`.

### `quick_sort_recursive()`

This function recursively sorts the segments on either side of the pivot.

```cpp
void quick_sort_recursive (int arr[], int left, int right){
    if (left < right){
        int pivot_pos = partition (arr, left, right);

        quick_sort_recursive (arr, left, pivot_pos - 1);
        quick_sort_recursive (arr, pivot_pos + 1, right);
    }
}
```

Here:

- `left` is the index of the first element in the current segment.
- `right` is the index of the last element in the current segment.
- `pivot_pos` is the final index of the pivot after partitioning.
- `if (left < right)` ensures that recursion stops when a segment contains at most one element.

Once the pivot reaches its correct position, it does not need to be included in either recursive call.

Unlike Merge Sort, Quick Sort does not need to merge the two sorted segments afterward because partitioning has already placed the pivot between them.

### `partition()`

This function rearranges the elements of the current segment around the pivot and returns the pivot's final position.

In this implementation, the first element is selected as the pivot.

```cpp
int partition (int arr[], int left, int right){
    int pivot_pos = left;
    int pivot = arr[left];

    left = left + 1;

    while (left <= right){
        while (left <= right && arr[left] <= pivot) left++;
        while (left <= right && arr[right] > pivot) right--;

        if (left < right) swap (&arr[left++], &arr[right--]);
    }

    swap (&arr[pivot_pos], &arr[right]);

    return right;
}
```

The partition process works as follows:

1. Store the pivot value and its initial position.
2. Start scanning from the element immediately after the pivot.
3. Move `left` forward while the current element is less than or equal to the pivot.
4. Move `right` backward while the current element is greater than the pivot.
5. If the pointers have not crossed, swap the two elements and move both pointers inward.
6. Once the pointers meet or cross, swap the pivot with `arr[right]`.
7. Return `right`, which is the pivot's final position.

After partitioning, the pivot separates the segment into two parts:

- Left partition: elements less than or equal to the pivot.
- Right partition: elements greater than the pivot.

**Important:** The pointer conditions and final pivot swap must be consistent with the chosen partition scheme. The implementation above uses the first element as the pivot and places it at the returned index.

## 4. Complexity

The time complexity depends on how evenly the pivot divides the array.

- **Best case:** `O(n log n)` — the pivot divides the array into approximately equal segments.
- **Average case:** `O(n log n)` — the partitions are reasonably balanced on average.
- **Worst case:** `O(n²)` — the pivot repeatedly produces highly unbalanced partitions, such as when the first element is chosen as the pivot in an already sorted array.

The auxiliary space complexity is:

- **Average case:** `O(log n)` for the recursive call stack.
- **Worst case:** `O(n)` for the recursive call stack.

Quick Sort is generally efficient in practice because partitioning is performed directly within the original array, requiring no separate temporary array for merging.

However, choosing the first element as the pivot can perform poorly on sorted or duplicate-heavy inputs. Alternative pivot-selection strategies and three-way partitioning can help address these cases.

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

### Test case 5 – All elements are equal

**Input**

```text
5
2 2 2 2 2
```

**Output**

```text
2 2 2 2 2
```

### Test case 6 – Duplicate-heavy input

**Input**

```text
8
1 1 2 2 3 3 4 4
```

**Output**

```text
1 1 2 2 3 3 4 4
```

---

## Concepts Practiced

- Divide-and-conquer algorithms
- Recursive function calls and base cases
- Pivot selection and partitioning
- Two-pointer scanning
- Array indexing and subarray boundaries
- In-place rearrangement using swapping
- Average-case and worst-case time complexity
- Recursive call stack and auxiliary space analysis

---
