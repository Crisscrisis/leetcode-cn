## leetcode724 寻找数组中心索引

### 思路
```
数组nums的中心索引为idx，nums各元素之和为sum，则满足如下条件：
2 x (nums[0] + nums[1] + ... + nums[idx -1]) = sum - nums[idx]
则可以根据此条件， 从左至右遍历判断
```

### code
```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 2) {
            return -1;
        }
        int leftIdx = 0;
        int sum = 0;
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum * 2 + nums.at(i) == sum) {
                return i;
            }
            leftSum += nums.at(i);
        }
        return -1;
    }
};
```