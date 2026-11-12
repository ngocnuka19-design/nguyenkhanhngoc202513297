# Find the Largest Subarray Formed by Consecutive Integers

## 1. Problem

Given an array of `n` integers, find the longest subarray that contains consecutive integers.

A subarray is considered valid if:
- All elements are distinct.
- The difference between the maximum and minimum elements is equal to the subarray length minus one.

In other words:

`max - min + 1 == length`

The elements do not need to appear in sorted order.

## 2. Understanding the Algorithm

A straightforward approach is to consider every possible starting position and expand the subarray while tracking its minimum and maximum values.

### 2.1 Brute Force

For each starting index `i`, initialize:
- `min` and `max` with `A[i]`.

Then iterate through the remaining elements:

1. Update the minimum and maximum values.
2. Check whether the current element has already appeared in the current subarray by comparing it with all previous elements.
3. If a duplicate is found, stop expanding the current subarray.
4. Otherwise, check whether the subarray contains consecutive integers using:

   `max - min + 1 == j - i + 1`

5. If the condition is satisfied and the current subarray is longer than the previously recorded result, update `max_length` and store the new subarray.

### 2.2 Why Does the Condition Work?

Suppose a subarray contains `k` distinct integers.

If:

`max - min + 1 == k`

then the number of possible integer values between the minimum and maximum is exactly equal to the number of elements.

Since all elements are distinct, every integer in that range must be present.

Therefore, the subarray contains consecutive integers, regardless of their original order.

### 2.3 Complexity Analysis

Let `n` be the length of the input array.

- The outer loop considers every possible starting position: `O(n)`.
- The inner loop expands the subarray: `O(n)`.
- Duplicate detection compares the current element with previously encountered elements: `O(n)`.
- Copying a newly discovered longest subarray takes up to `O(n)`.

Overall:

- Time Complexity: `O(n^3)`
- Auxiliary Space Complexity: `O(n)` for storing the resulting subarray.

The algorithm does not require the input values to be within a limited range, so it can handle negative and large integer values.

## 3. Implementation

```cpp
    int max_length = 0;
    int result[n] = {0};

    for (int i = 0; i < n; i++){
        int min = A[i];
        int max = A[i];

        for (int j = i; j < n; j++){
            if (A[j] > max) max = A[j];
            if (A[j] < min) min = A[j];

            bool duplicate = false;

            for (int k = i; k < j; k++){
                if (A[k] == A[j]){
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) break;

            if (max_length < (max - min + 1) &&
                (max - min + 1) == j - i + 1){

                max_length = max - min + 1;

                for (int k = 0; k < max_length; k++){
                    result[k] = A[i + k];
                }
            }
        }
    }

    for (int i = 0; i < max_length; i++){
        cout << result[i] << "  ";
    }
```

## 4. Test Cases

### 4.1 Test Case 1 - Entire Array Is Consecutive

**Input**

```text
5
1 2 3 4 5
```

**Output**

```text
1  2  3  4  5
```

### 4.2 Test Case 2 - Unsorted Consecutive Subarray

**Input**

```text
7
10 12 11 14 13 20 21
```

**Output**

```text
10  12  11  14  13
```

### 4.3 Test Case 3 - Multiple Valid Subarrays

**Input**

```text
8
1 2 4 3 8 7 6 5
```

**Output**

```text
4  3  8  7  6  5
```

### 4.4 Test Case 4 - Duplicate Elements

**Input**

```text
7
1 2 2 3 4 5 6
```

**Output**

```text
2  3  4  5  6
```

### 4.5 Test Case 5 - Negative and Large Values

**Input**

```text
6
-5 -3 -4 100000 99999 99998
```

**Output**

```text
-5  -3  -4
```

### 4.6 Test Case 6 - No Consecutive Subarray of Length Greater Than One

**Input**

```text
5
1 5 9 13 17
```

**Output**

```text
1
```

