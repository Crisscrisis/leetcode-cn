## leetcode485 最大连续1的个数

### 思路
```
需要一个当前连续1的计数sum，和最大计数maxSum，直接遍历，遇到1则计数值增加1，遇到0，则比较sum和maxSum，将更大的那一个存给maxSum，并且sum清零。
```

### code
```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int sum = 0;
        int maxSum = sum;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == 1) {
                sum++;
            } else {
                if (maxSum < sum) {
                    maxSum = sum;
                }
                sum = 0;
            }
        }
        if (maxSum < sum) {
            maxSum = sum;
        }
        return maxSum;
    }
};
```