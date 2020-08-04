## leetcode136 只出现一次的数字

### 思路
```
对所有元素做一次异或运算，相同的两个数异或之后结果为0，最终剩下的就是那个只出现一次的数字。
注意：ans = ans ^ i计算速度要远快于 ans ^= i
```

### code
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto i:nums) {
            ans = ans ^ i;
        }
        return ans;
    }
};
```