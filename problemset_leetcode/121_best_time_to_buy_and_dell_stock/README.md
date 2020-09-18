## leetcode121 买卖股票的最佳时机

### 思路
```
dp解法：dp[i]前i天的最大收益。
minprice = min(minprice, prices[ij])
dp[i] = max(dp[i-1], prices[i] - minprice)
dp解法比单调栈解法更快
单调栈解法：维护一个单调递增的栈，若当前元素小于栈顶，则出栈，直到栈为空或者当前元素大于等于栈顶，每次出栈，都要计算一次当前最大值。
最终每个元素都入栈，都进行计算。返回维护的最大值
```

### code
```c++
class Solution {
public:
    // dp
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() < 2) {
            return 0;
        }
        int minPrice = prices[0];
        vector<int> dp(prices.size(), 0);
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp.back();
    }
    // monotone stack
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> st;
        prices.emplace_back(-1);
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && st.back() > prices[i]) {
                ans = max(ans, st.back() - st.front());
                st.pop_back();
            }
            st.emplace_back(prices[i]);
        }
        return ans;
    }
};
```