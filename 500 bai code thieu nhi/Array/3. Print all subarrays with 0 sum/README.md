# Print All Subarrays with Zero Sum

## 1. Problem

Given an array of integers, print all contiguous subarrays whose elements sum up to zero.

This problem extends [Check Whether a Zero-Sum Subarray Exists](README%20of%20previous%20prob.md).

For the Prefix Sum concept, Merge Sort implementation, and basic algorithm explanation, refer to the original problem's README.

## 2. Understanding the Algorithm

### 2.1 From Detecting to Printing

In the original problem, we only needed to determine whether at least one pair of equal prefix sums existed.

In this problem, we need to find **all possible pairs** of equal prefix sums because each pair corresponds to a zero-sum subarray.

After sorting the prefix sum array, equal values are grouped together.

For each group containing multiple equal prefix sums:

1. Use two nested loops to generate every possible pair within the group.
2. Retrieve the original positions of both prefix sums.
3. Calculate the corresponding subarray boundaries.
4. Print all elements within those boundaries.

### 2.2 Recovering the Original Subarray

Recall that if two prefix sums have the same value:

\`P[i] = P[j]\`

Then:

\`A[i] + ... + A[j-1] = 0\`

Since the prefix sum array is sorted, its elements are no longer necessarily in their original positional order. Therefore, we use the stored \`pos\` values to recover the correct subarray.

For any pair of equal prefix sums:

\`\`\`cpp
int start = min(prefix[a].pos, prefix[b].pos) + 1;
int end = max(prefix[a].pos, prefix[b].pos);
\`\`\`

The corresponding zero-sum subarray is:

\`A[start ... end]\`

### 2.3 Generating All Pairs

Suppose a group contains three equal prefix sums:

\`\`\`text
Index:  0  1  2
Value:  5  5  5
\`\`\`

The nested loops generate:

\`\`\`text
(0, 1)
(0, 2)
(1, 2)
\`\`\`

Therefore, a group containing \`m\` equal prefix sums produces:

\`\`\`
m * (m - 1) / 2
\`\`\`

possible pairs, each representing a different zero-sum subarray.


## 3. Implementation

### 3.1 Modified Function

Unlike the original problem, this implementation also receives the original array \`arr[]\`, which is required to print the subarrays.

\`\`\`cpp
void merge_sort_prefix (prefix_sum prefix[], int length, int arr[]);
\`\`\`

### 3.2 Main Changes

- Sort the prefix sum array using the existing Merge Sort implementation.
- Identify groups of equal prefix sums.
- Use nested loops to enumerate every possible pair in each group.
- Calculate the original subarray boundaries using the stored positions.
- Print each corresponding subarray.
- If no duplicate prefix sums are found, report that no zero-sum subarray exists.

The remaining functions, including the prefix sum structure and Merge Sort implementation, are reused from the original problem.

## 4. Test Cases

### 4.1 Multiple Zero-Sum Subarrays

**Input**

\`\`\`text
10
3 4 -7 3 1 3 1 -4 -2 -2
\`\`\`

**Output**

\`\`\`text
{ 3 4 -7 }
{ 3 4 -7 3 1 3 1 -4 -2 -2 }
{ 3 1 3 1 -4 -2 -2 }
{ 4 -7 3 }
{ -7 3 1 3 }
{ 3 1 -4 }
\`\`\`

### 4.2 No Zero-Sum Subarray

**Input**

\`\`\`text
5
1 2 3 4 5
\`\`\`

**Output**

\`\`\`text
No zero-sum subarray exists.
\`\`\`

### 4.3 Multiple Equal Prefix Sums

**Input**

\`\`\`text
4
0 0 0 0
\`\`\`

**Output**

There are 10 zero-sum subarrays, corresponding to all possible contiguous subarrays of the input array.