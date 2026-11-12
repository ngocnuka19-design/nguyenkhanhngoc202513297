# Find the Duplicate Element in a Limited Range Array

## 1. Problem

Given an array of size `n` containing elements between `1` and `n-1`, find the duplicate number in the array without using any extra space.

Assume that exactly one distinct value is repeated, although it may appear more than twice.

## 2. Understanding the Algorithm

There are several approaches to solve this problem, each with different time and space complexities.

### 2.1 Brute Force

The simplest approach is to compare every element with the remaining elements in the array.

For each element `arr[i]`, iterate through the elements after it and check whether any of them have the same value.

If a match is found, that value is the duplicate.

- Time Complexity: `O(n^2)`
- Space Complexity: `O(1)`

### 2.2 Marking

Since all elements are within the range `[1, n-1]`, we can use the array itself as a marking mechanism.

The idea is to use the sign of an element to indicate whether its corresponding value has already appeared.

For each element:
1. Take its absolute value and use it as an index.
2. Check the sign of `arr[index]`.
3. If it is negative, the corresponding value has already been visited. Therefore, it is the duplicate.
4. Otherwise, negate `arr[index]` to mark it as visited.

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

Note: This approach modifies the original array.

### 2.3 Sorting First

Another straightforward approach is to sort the array first.

After sorting, duplicate elements will appear next to each other.

Iterate through the sorted array and compare each element with its previous element. If they are equal, the duplicate has been found.

Note: This approach modifies the original array.

## 3. Implementation

### 3.1 Brute Force

```cpp
for (int i = 0; i < length; i++){
        for (int j = i+1; j < length; j++){
            if (input[i] == input[j]){
                cout << "The duplicate element is: " << input[i];
                return 0;
            }
        }
    }
```

### 3.2 Marking

```cpp
 int max = A [0];
    for (int i = 0; i < n -1; i++){
        if (A[i+1] > A[i]) max = A[i+1];
    }

    int visted[max] = {0};

    for (int i = 0; i < max; i++){
        if (visted[A[i]] == 1){
            cout << "The duplicate element is: " << A[i];
            return 0;
        }
        else visted [A[i]] = 1;
    }
```

### 3.3 Sorting First

```cpp
merge_sort(A, n);

    for (int i = 0; i < n-1; i++){
        if(A[i] == A[i+1]) {
            cout << "The duplicate element is: " << A[i];
            return 0;
        }
    }
```

## 4. Test Cases

### 4.1 Test Case 1 - Minimum Size

**Input**

```text
2
1 1
```

**Output**

```text
1
```

### 4.2 Test Case 2 - Duplicate at the Beginning

**Input**

```text
5
2 2 1 3 4
```

**Output**

```text
2
```

### 4.3 Test Case 3 - Duplicate at the End

**Input**

```text
5
1 2 3 4 4
```

**Output**

```text
4
```

### 4.4 Test Case 4 - Unsorted Array

**Input**

```text
7
3 1 4 2 5 3 6
```

**Output**

```text
3
```

### 4.5 Test Case 5 - Multiple Occurrences of the Same Value

**Input**

```text
7
2 1 3 2 4 2 5
```

**Output**

```text
2
```