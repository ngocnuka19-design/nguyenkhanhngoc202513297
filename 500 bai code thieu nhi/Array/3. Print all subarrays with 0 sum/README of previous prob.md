# Check Whether a Zero-Sum Subarray Exists

## 1. Problem

Given an array of integers, check whether there exists a contiguous subarray whose elements sum up to zero.

A zero-sum subarray must contain at least one element, and its elements must occupy consecutive positions in the original array.

## 2. Understanding the Algorithm

A useful approach to solve this problem is to combine Prefix Sum and Merge Sort.

### 2.1 Prefix Sum

The main idea is based on the observation that if two prefix sums have the same value, the elements between their corresponding positions must sum up to zero.

Define the prefix sum:

`P[i] = A[0] + A[1] + ... + A[i-1]`

We also include an initial prefix sum:

`P[0] = 0`

For any two positions `i` and `j`, where `i < j`:

`P[j] - P[i] = A[i] + ... + A[j-1]`

Therefore, if:

`P[i] == P[j]`

Then:

`P[j] - P[i] == 0`

This means that a zero-sum subarray exists.

### 2.2 Merge Sort

Instead of comparing every pair of prefix sums, we can sort them first.

After sorting, equal prefix sums will appear next to each other.

The algorithm works as follows:

1. Construct the prefix sum array, including the initial value `0`.
2. Store each prefix sum together with its original position using a structure containing `value` and `pos`.
3. Sort the prefix sum array using Merge Sort.
4. Iterate through the sorted array and compare adjacent elements.
5. If two adjacent prefix sums have the same value, a zero-sum subarray exists.
6. If no equal values are found, no zero-sum subarray exists.

### 2.3 Complexity Analysis

Let `n` be the length of the original array.

- Constructing the prefix sum array: `O(n)`.
- Sorting the prefix sum array using Merge Sort: `O(n log n)`.
- Checking adjacent prefix sums: `O(n)`.

Overall:

- Time Complexity: `O(n log n)`
- Auxiliary Space Complexity: `O(n)` for Merge Sort.

Note: The original positions are retained in the structure, although they are not necessary when the objective is only to determine whether a zero-sum subarray exists.

## 3. Implementation

### 3.1 Prefix Sum Structure

```cpp
typedef struct
{
    int value;
    int pos;
} prefix_sum;
```

Each element stores:
- `value`: The calculated prefix sum.
- `pos`: Its corresponding position in the original array. The initial prefix sum has position `-1`.

### 3.2 Merge Sort Functions

```cpp
void merge_sort (prefix_sum arr[], int length);
void merge_sort_recursive (prefix_sum arr[], int left, int right);
void merge_sorted_array (prefix_sum arr[], int left, int middle, int right);
```

The Merge Sort implementation sorts the prefix sums in ascending order while preserving their associated original positions.

### 3.3 Check for Zero-Sum Subarray

```cpp
void merge_sort_prefix (prefix_sum prefix[], int length){
    merge_sort(prefix, length);

    for (int i = 0; i < length - 1; i++){
        if (prefix[i].value == prefix[i + 1].value){
            cout << "Zero-sum subarray exists.";
            return;
        }
    }

    cout << "No zero-sum subarray exists.";
}
```

### 3.4 Main Function

```cpp
int main (){
    int array[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int length = 10;

    prefix_sum prefix[length + 1];

    prefix[0] = {0, -1};

    int sum = 0;

    for (int i = 0; i < length; i++){
        sum = sum + array[i];

        prefix[i + 1] = {sum, i};
    }

    merge_sort_prefix(prefix, length + 1);

    return 0;
}
```

## 4. Test Cases

### 4.1 Test Case 1 - Zero-Sum Subarray at the Beginning

**Input**

```text
5
1 2 -3 4 5
```

**Output**

```text
Zero-sum subarray exists.
```

### 4.2 Test Case 2 - Zero-Sum Subarray in the Middle

**Input**

```text
5
4 2 -2 1 5
```

**Output**

```text
Zero-sum subarray exists.
```

### 4.3 Test Case 3 - Zero-Sum Subarray at the End

**Input**

```text
5
1 2 3 -2 -4
```

**Output**

```text
Zero-sum subarray exists.
```

### 4.4 Test Case 4 - Entire Array Has a Zero Sum

**Input**

```text
4
1 2 -3 0
```

**Output**

```text
Zero-sum subarray exists.
```

### 4.5 Test Case 5 - No Zero-Sum Subarray

**Input**

```text
5
1 2 3 4 5
```

**Output**

```text
No zero-sum subarray exists.
```

### 4.6 Test Case 6 - Negative and Positive Elements

**Input**

```text
6
-5 2 3 7 -4 -3
```

**Output**

```text
Zero-sum subarray exists.
```