# [1886. Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

### O(N^2) Time solution

- Suppose we are at index i, j, let us find a relation of this position with it's position in various rotations. i. e

```
- 0 deg rotation : i, j will point to i, j
- 90 deg rotation : i, j will point to j, n - i - 1
- 180 deg rotation : i, j will point to n - i - 1, n - j - 1
- 270 deg rotation : i, j will point to n - j - 1, i
```

- We denote these rotations by boolean variables, initially we assume all these rotations are valid, so we set them all to true. Here

```
c[0] -> 0 deg rotation,
c[1] -> 90 deg,
c[2] -> 180 deg,
c[3] -> 270 deg
```

- Then, we loop over all elements and check if that particular rotation is valid or not. If not, we turn it to false.
- In the end, we simply check if any of the rotations is still possible or not.

> _This same code can also be used to find out the valid rotation, i,e 0deg / 90deg / 180 deg/ 270 deg by checking the boolean value in c[0], c[1]. c[2], c[3] respectively._

### Code

```cpp
class Solution {
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        bool c[4];
        memset(c, true, sizeof(c));
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j])
                    c[0] = false;
                if (mat[i][j] != target[n - j - 1][i])
                    c[1] = false;
                if (mat[i][j] != target[n - i - 1][n - j - 1])
                    c[2] = false;
                if (mat[i][j] != target[j][n - i - 1])
                    c[3] = false;
            }
        }
        return c[0] || c[1] || c[2] || c[3];
    }
};
```
