## leetcode70 爬楼梯

### 思路
```
动态规划，核心状态转移：
假设dp[n]是第n阶台阶的趴法，则他取决于n-1阶台阶的爬法加上n-2阶台阶的爬法，初始状态1阶有1种，2阶有2种
```

### code
```c++
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int dp[1000];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```