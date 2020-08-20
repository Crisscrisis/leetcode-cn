## leetcode322 零钱兑换

### 思路
```
动态规划,核心状态转移：
设dp[n]是以总金额为n时，所需要的最少兑换次数，则对每个金额i:[0,n]，遍历所有硬币面值，有如下情况：
1.若当前金额i小于所有硬币面值coin，则不存在兑换方法，跳过；
2.若当前金额i大于等于某一硬币面值coin，则dp[i] = min(dp[i], dp[i-coin] + 1)，dp[i]可能会随着coin的变化而变化，故需要不断比较

```

### code
```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {

            for(auto coin: coins) {
                if(i < coin) {
                    continue;
                } else {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
```