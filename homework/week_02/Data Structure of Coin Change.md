## Algorithm
The core of dynamic programming (Quy hoạch động) is reusing the results of smaller, previous subproblems to calculate the larger ones. For e.g., in the "coin change" problem, if we want to find the minimum steps (coins) to make a total amount of 6 using available coins of 1, 3, and 4, we can consider 3 cases:
- Subtract 6 - 4 = 2 (choosing one coin of value 4), so the minimum steps will be the minimum steps to get a total of 2 (2 steps) + 1.
- Subtract 6 - 3 = 3 (choosing one coin of value 3), so the minimum steps will be the minimum steps to get a total of 3 (1 step) + 1.
- Subtract 6 - 1 = 5 (choosing one coin of value 1), so the minimum steps will be the minimum steps to get a total of 5 (2 steps) + 1.
Frankly, finding the minimum steps for 6 fundamentally boils down to finding the minimum steps for smaller amounts and then,  adding 1. Therefore, it will consider as partially recursive (Using memories to store the previous calculation, thus reducing the total amount of calculations needed)
## Data structure
- `Coins array`: - Stores the available coin denominations.
- `Dynamic programming array`: - Stores the minimum number of steps (coins) for target amounts ranging from 0 to n (the index represents the amount of money, and the value at each cell represents the minimum steps (coins) needed for that amount).