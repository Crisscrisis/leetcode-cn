## leetcode 62  不同路径

### 思路
```
为了表示方便，可以构建dp[m+1][n+1]，则dp[1][1]表示左上角，dp[m][n]表示右下角
二维数组初始化：vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
dp[i][j]表示当前位置的所有方法数，可以发现，存在可重复子问题。
可重复子问题：当前的方法dp[i][j]=dp[i+1][j] + dp[i][j+1]
若为边界，则dp值为1，因为若为右边界，则只能向下走；若为下边界，则只能向右走。
botton to top 方法：动态规划，遍历所有dp数组，从右下角开始，逐步计算，算到左上角。左上角为结果。
top to button 方法：递归，从左上角开始算，要计算左上角的值，就需要他下面和右边的值。注意剪枝：若当前dp值已不为0，则说明已经计算过，直接返回，无需再计算，否则会超时。
由于递归有剪枝，且递归只是计算所走过的路径，而没有计算所有dp[m+1][n+1]数组，所以比自底向上计算速度更快。

```

### code
```c++
class Solution {
public:
    // button to top
#if 0
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m; i > 0; i-- ) {
            for (int j = n; j > 0; j--) {
                if(i == m || j == n) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[1][1];
    }
#endif
    // top to button
    int recurse(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        } else if (i < m && j < n) {
            dp[i][j] = recurse(i + 1, j, m, n, dp) + recurse(i, j + 1, m, n, dp);
            return dp[i][j];
        }
        return 1;
    }
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = recurse(1, 1, m, n, dp);
        return ans;
    }
};
```