## Recursive

### 1. Problem

Solving the **Tower of Hanoi** using recursion.

- **Input:** An integer `n` as the number of disks.
- **Output:** The list of steps to move all disks from peg A to peg C.
### 2. Algorithm

#### Base case: `n = 1`

When there is only 1 disk, simply move it from the source peg to the destination peg.

```
if (num_disk == 1)
    transfer(org, end);
```

#### Understanding why recursion works

- **Developing the algorithm using `n = 3`:**
    - First: Move 2 disks from peg A to peg B to free up the space so that we can move the last (biggest) disk from A to C, using C as an in between.
    - Second: Move the last disk from A to C.
    - Last: Move 2 disks from B to C, using A as a in between peg.
        
- **Why recursion can work even with `n > 3` (e.g. `n = 4`):**
    - First: Move 3 disks from A to B. This is the same problem as `n = 3`, so we can solve it using the same method.
    - Second: Move the last (biggest) disk from A to C.
    - Third: Move 3 disks from B to C, using A as a in between  peg. This still works because disk 4 is already on C, and every other disk is smaller than it, so they can all be placed on top of it.
    - Therefore, we can keep applying the same process to `n - 1`, `n - 2`, ..., until we reach the base case `n = 1`.
### 3. Implementation of Recursion

When there is more than one disk, the problem is divided into three steps:

**Step 1:** Move `n - 1` disks from the ``source (org)`` peg to the ``temporary (mid)`` peg.

```
Tower_of_Hanoi(num_disk - 1, org, end, mid);
```

Here, `end (C)` acts as the in between peg.

**Step 2:** Move the biggest disk from the`` source (org)`` peg to the ``destination (end)`` peg.

```
transfer(org, end);
```

**Step 3:** Move `n - 1` disks from the ``temporary (mid)`` peg to the ``destination (end)`` peg.

```
Tower_of_Hanoi(num_disk - 1, mid, org, end);
```

Here, `org (A)` acts as the in between peg.

Therefore:

```text
Tower_of_Hanoi(n, A, B, C)

     Move n-1 disks
        A → B
		using C

    Move largest disk
        A → C

    Move n-1 disks
          B → C
	      using A
```


### Test case
#### Test case 1 – One disk

**Input**

```text
1
```

**Expected output**

```text
Moving disk form A to C
1
```
#### Test case 2 – Three disks

**Input**

```text
3
```

**Expected output**

```text
Moving disk form A to C
Moving disk form A to B
Moving disk form C to B
Moving disk form A to C
Moving disk form B to A
Moving disk form B to C
Moving disk form A to C
7
```

---
## Non-Recursive (Stack)

### 1. Problem & Concept

Solving the **Tower of Hanoi** non-recursively by using an explicit **Stack** structure.

- **Why Stack?** Standard recursion relies on the system's Call Stack. By managing our own Stack on Heap memory, we avoid stack overflow errors for large values of `n` and control the task execution flow directly. (Basically, Stack is also using a recursive algorithm, but not a "recursive" memory-organization)
- **Task Structure:** Each stack element represents a sub-problem stored as a `task` structure containing parameters:
  - `num_disk`: Number of disks to move.
  - `org`: Source peg.
  - `mid`: Auxiliary/temporary peg.
  - `end`: Destination peg.
### 2. Algorithm & LIFO Order Logic

Since a Stack operates on the **LIFO (Last-In, First-Out)** principle, the task pushed **last** will be executed **first**. 

To maintain the correct sequence of execution equivalent to recursion, we must push tasks onto the Stack in **reverse order**:
```
st.push({temp.num_disk -1, temp.mid, temp.org, temp.end});
st.push({1, temp.org, temp.mid, temp.end});
st.push({temp.num_disk - 1, temp.org, temp.end, temp.mid});
```

The original recursive order is:

```
1. Tower_of_Hanoi(n - 1, org, end, mid)
2. Move disk from org to end
3. Tower_of_Hanoi(n - 1, mid, org, end)
```
### 3. Some Things to Note
- `temp`**:** `pop()` removes the current frame from the Stack. However, we still need its information (`num_disk`, `org`, `mid`, and `end`) to create the next tasks. Therefore, `temp` is used to temporarily store the current frame.
- In `Tower_of_Hanoi`, each task consists of only three fixed steps. We can take advantage of LIFO and simply push these steps in reverse order.
  However, in a more complicated recursive function, a task may need to be paused halfway, execute a smaller recursive task, and then return to a specific point in the original task. 
  In that case, a `state` variable would be useful to remember **where the task stopped and what it should do next**.