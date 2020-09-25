## leetcode300 最长上升子序列

### 思路
```
动态规划,核心状态转移：
设dp[n]是以nums[n]作为结尾对应的,最长上升子序列，则对每个位置i，遍历一切j<i,有如下情况：
1.nums[i] <= nums[j],则nums[i]不能在nums[j]已有的序列之后添加，跳过；
2.nums[i] > nums[j],则nums[i]可以在nums[j]已有的序列之后添加,dp[i] = max(dp[i], dp[j] + 1)；
如此,可以计算出dp[n],最终求出最长上升子序列
```

### code
```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int len = nums.size();
        vector<int> dp(len, 0);
        int maxVal = 1;
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (maxVal < dp[i]) {
                    maxVal = dp[i];
                }
            }
        }
        return maxVal;
    }
};
```