## leetcode209 长度最小的子数组

### 思路
```
考虑使用一个滑窗。遍历当前的数组，存储下从该滑窗内包含的数组的和，滑窗的起始位置arrayStart为0，终止位置为当前遍历的位置。如果当前滑窗的和sum大于等于s，且当前滑窗的和sum减去滑窗最左侧的元素的值之后，仍然大于等于s，则滑窗向右移动一格，且更新sum和arrayStart，并且比较minLen和tmpLen，取更小的那个赋值给minLen。照此规律遍历一遍，即可得到结果。
```

### code
```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int tmpLen = 0;
        int minLen = 0;
        int sum = 0;
        int arrayStart = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
            tmpLen++;
            if (sum >= s && minLen == 0) {
                minLen = tmpLen;
            }
            while ((sum - nums.at(arrayStart)) >= s) {
                sum = sum - nums.at(arrayStart);
                arrayStart++;
                tmpLen--;
                if (minLen > tmpLen || minLen == 0) {
                    minLen = tmpLen;
                }
            }
        }
        return minLen;
    }
};
```