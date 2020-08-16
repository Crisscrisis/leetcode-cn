## leetcode416 分割等和子集

### 思路
```
动态规划，0-1背包问题，总重量=nums的sum/2，最大物品个数=nums.size()，dp[n][w]表示，前n个物品，总重量为w，能否刚好放下
则状态转移为：
若第i个物品重量nums[i-1]>当前总重量，则一定放不下第i个，则此时dp[i][j]=dp[i-1][j]；
若第i个物品重量nums[i-1]<当前总重量，
则此时可以选择放或者不放，
    若不放，则dp[i][j]=dp[i-1][j]；
    若放，则dp[i][j]=dp[i-1][j - nums[i-1]]
    两者有一个为true，则dp[i][j]即为true
```

### code
```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum >>= 1;
        int n = nums.size();
        vector<vector<bool>>dp(n+1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};
```