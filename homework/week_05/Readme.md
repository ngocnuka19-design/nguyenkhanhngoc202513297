# Selection Sort and Insertion Sort

## Selection Sort

### 1. Problem

Implement **Selection Sort** to sort an array of `n` integers in ascending order.

* **Input:** An integer `n`, followed by `n` integers.
* **Output:** The sorted array in ascending order.

### 2. Understanding the Algorithm

The main idea of Selection Sort is to divide the array into two parts:

* The **sorted part** on the left.
* The **unsorted part** on the right.

For each position `i`, we find the smallest element in the unsorted part and move it to `a[i]`.

For example:

```text
101 23 57 13 25 121 87 36
```

At the first step, we search the whole array for the smallest element:

```text
101 23 57 13 25 121 87 36
                  ↓
                 13
```

Then swap it with the first element:

```text
13 23 57 101 25 121 87 36
^^
sorted
```

At the next step, we ignore the first element because it is already in its final position.

We search the remaining part:

```text
13 | 23 57 101 25 121 87 36
     ^^^^^^^^^^^^^^^^^^^^^^^
          unsorted part
```

The same process is repeated until the whole array is sorted.

Therefore, after each iteration, one more element is placed into its final position.

### 3. Implementation

```cpp
 for (int i = 0; i < 13; i++) {
        int min = i;

        for (int j = i + 1; j < 13; j++){
            if(A[j] < A[min]) min = j;
        }

        int temp = A[i]; A[i] = A[min]; A[min] = temp;
 }
```

The variable `min` stores the **index** of the smallest element found in the unsorted part.

An important point is that we do not swap every time we find a smaller element. We first finish searching for the minimum, then perform one swap at the end of the iteration.

### 4. Complexity

The number of comparisons is always:

```text
(n - 1) + (n - 2) + ... + 1
```

Therefore:

* Best case: **O(n²)**
* Average case: **O(n²)**
* Worst case: **O(n²)**

Selection Sort always needs to search through the remaining unsorted part, even if the array is already sorted.

---

## Insertion Sort

### 1. Problem

Implement **Insertion Sort** to sort an array of `n` integers in ascending order.

* **Input:** An integer `n`, followed by `n` integers.
* **Output:** The sorted array in ascending order.

### 2. Understanding the Algorithm

Insertion Sort works similarly to **sorting cards in your hand**.

The array is divided into:

* A **sorted part** on the left.
* An **unsorted part** on the right.

At each step, we take the next element from the unsorted part and **move it to its correct position in the sorted part**.

For example:

```text
23 57 101 | 13 25 121
^^^^^^^^^   ^^^^^^^^^
 sorted      unsorted
```

Take `13`:

```text
23 57 101 | 13
```

We compare `13` with the elements before it. Whenever `13` is smaller than the current element, we swap them.

```text
23 57 13 101
23 13 57 101
13 23 57 101
```

After these swaps, `13` has been moved to its correct position.

Now:

```text
13 23 57 101 | 25 121
^^^^^^^^^^^^^   ^^^^^^^
   sorted       unsorted
```

We continue the same process with the next element.

Therefore, after each iteration, the part `a[0..i]` is sorted.

### 3. Implementation

```cpp
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[i] < A[j])
                swap(&A[i], &A[j]);
        }
    }
```

Here:

* `i` points to the current element from the unsorted part.
* `j` goes through the elements in the sorted part.
* If `A[i]` is smaller than `A[j]`, they are swapped.
* These swaps move `A[i]` toward its correct position.

After each iteration:

```text
a[0..i]
```

is sorted.

Note that this is not the textbook implementation of Insertion Sort. The textbook version usually uses shifting instead of swapping. Shifting is generally more efficient because it requires fewer assignments when moving an element through the sorted part. However, this implementation still follows the main idea of Insertion Sort: taking the next element and placing it into its correct position in the sorted part.

### 4. Complexity

The complexity depends on the initial order of the array.

* **Best case:** The array is already sorted → **O(n)**
* **Average case:** **O(n²)**
* **Worst case:** The array is sorted in reverse order → **O(n²)**

Insertion Sort performs well when the array is already sorted or almost sorted.

---

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

```
6
3 -1 2 3 0 -1
```

**Output**

```
-1 -1 0 2 3 3
```
