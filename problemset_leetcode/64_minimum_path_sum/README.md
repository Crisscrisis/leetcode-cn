## leetcode 64  最小路径和

### 思路
```
为了方便迭代，构造一个m+1，n+1的dp数组，最左列和最上行的情况，dp等于当前grid值+上一步dp，其余普通情况，dp等于当前grid值+上两步中dp较小的那个。
最终返回dp[m][n]
```

### code
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid.at(0).empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid.at(0).size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if (i == 1 || j == 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + grid[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
```