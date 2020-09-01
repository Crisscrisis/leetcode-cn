## leetcode486 预测赢家

### 思路
```
该问题属于零和博弈，有一个minmax策略，即最小化对方可以获得的最大收益。因为每个人都是理性的，每个人自己选择时，都会选择当前情况下的最大收益。
则自己获得最大收益与对方获得最小收益是等价的。
设helper(nums,left,right)是在数组nums[left,right]的范围内，可以获得的最高分。
则最终的结果，即为helper(nums,0,nums.size()-1)
子问题：假设对于任意的left，right，有：
1.若left==right，则当前可以获得的最高分即为nums[left]，因为没得选
2.若left<right，则当前可以有两个选择:
    a.选择nums[left+1]，则留给对方的情景即为[left+1,right]，则对方获得的最高分为helper(nums,left+1,right)，我方获得的最高分为[left,right]的总分，减去helper(nums,left+1,right)，因为nums[left+1]我们已经选择了;
    b.选择nums[right-1]，则留给对方的情景即为[left,right-1]，则对方获得的最高分为helper(nums,left,right-1)，我方获得的最高分为[left,right]的总分，减去helper(nums,left,right-1)，因为nums[right-1]我们已经选择了;
比较这两个情景，选择更大的即可。
为了避免重复计算，用mem[left][right]来记录[left,right]情景下的最高分helper(nums,left,right)
```

### code
```c++
class Solution {
public:
    vector<vector<int>> mem;    // mem[left][right]: biggest numbers we can get in situation nums[left, right]
    vector<int> sum;    // sum[n]: sum between nums[0, n]

    int helper(vector<int>& nums, int left, int right) { // biggest numbers in situation nums[left, right]
        if (left == right) {
            return nums[left];
        }

        if (mem[left][right] != -1)
            return mem[left][right];

        int total = sum[right] - sum[left] + nums[left];    // sum between nums[left, right]
        int ans = max(total - helper(nums, left + 1, right),    // if we i chose left, then you will get the biggest numbers in situation nums[left + 1, right]
                                                                // thus, the present numbers we get is total - helpers(nums, left + 1, right)
                        total - helper(nums, left, right-1));   // if we i chose right, then you will get the biggest numbers in situation nums[left, right - 1]
                                                                // thus, the present numbers we get is total - helpers(nums, left, right - 1)
        return mem[left][right] = ans;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        mem.resize(n, vector<int>(n, -1));
        sum.resize(n);
        int t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            t += nums[i];
            sum[i] = t;
        }
        int total = sum.back();
        int maxV = helper(nums, 0, n-1);
        return maxV >= total-maxV;
    }
};
```