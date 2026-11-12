#Sort binary in linear time
## 1. Problem
Given a binary array, sort it in linear time and constant space. The output should print all zeros, followed by all ones.

## 2. Understanding the Algorithm
Easy to see that the intial array given only contains two value: `0` and `1`. A clever way to solve this problem is to count all the `0` value in the given array. Store that `count`
Then, create an output array with the same length that put `count` number of `0` at first, then fill the rest elements with `1`.
### 3. Implementation
```cpp
int output [length] = {0};
    for (int i = 0 + count; i < length; i++){
        output [i] = 1;
    }
```
 ## 4. Test case
### 4.1 Test case 1 - One element
**Input**

```text
1
1
```

**Output**

```text
7
```

### 4.2 Test case 2 - Sorted case

**Input**

```text
7
0   0   0   1   1   1   1
```

**Output**

```text
0   0   0   1   1   1   1
```

### 4.3 Normal case
**Input**
```text
7
0   1   1   1   0   1   0
```

**Output***
```text
0   0   0   1   1   1   1
```
