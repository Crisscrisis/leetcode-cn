## leetcode 63  不同路径 II

### 思路
```
为了表示方便，可以构建dp[m+1][n+1]，则dp[1][1]表示左上角，dp[m][n]表示右下角
dp[i][j]表示当前位置的所有方法数，可以发现，存在可重复子问题。
如果探路顺序为左上->右下，则有
可重复子问题：当前的方法dp[i][j]=dp[i-1][j] + dp[i][j-1]
这样做的好处：因为有可能边界也有障碍，故这种表示方法，边界情况不需要特别考虑，只需要初始化左上起始点即可。
注意：左上起始点，如果有障碍，则dp[1][1] = 0，如果没有障碍，则dp[0][0] = 1
botton to top 方法：动态规划，遍历所有dp数组，从左上角开始，逐步计算，算到右下角。右下角为结果。

结合leetcode 62，这类问题，从左上到右下，和从右下到左上，结果是一样的。
左上到右下：当前dp[i][j] = dp[i-1][j] + dp[i][j-1]，最终结果在dp[m][n]
右下到左上：当前dp[i][j] = dp[i+1][j] + dp[i][j+1]，最终结果在dp[1][1]
但是由于从左上到右下，由于dp本身就在左侧和上侧扩充了一列一行，故边界情况不需要特殊考虑，使用起来更加方便，因此推荐使用左上到右下的方式。

```

### code
```c++
class Solution {
public:
    // left top -> right button
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid.at(0).empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j] = obstacleGrid[0][0] == 1 ? 0 : 1;
                } else {
                    if (obstacleGrid[i - 1][j - 1] == 0) {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
```