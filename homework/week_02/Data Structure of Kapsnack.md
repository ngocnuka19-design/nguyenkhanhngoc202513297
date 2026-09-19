Basically the same thing as [[Data Structure of Coin Change]], create a `dynamic programming array` of all the available weight (from 0 to 1000). For each weight, we have 2 options: choosing that food, and not. 

## Data Structure
- `Food items array (or list)`: Store the characteristic of all the available food (their weights and their calories)
- `Dynamic programming array`: Stores the maximum calories achievable for weight capacities ranging from `0` to `1000` kg (the index represents the capacity, and the value at each cell represents the maximum calories for that exact weight).