## leetcode283 移动零

### 思路
```
快慢指针，指针j为慢指针，用于指向存储的非0元素的位置，快指针i用于遍历整个数组，如果当前i所指向的元素非0，则将其存入j指向的位置，并且记录下长度，根据记录的长度，将最后几位补为0
```

### code
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int j = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums.at(i) != 0) {
                nums.at(j++) = nums.at(i);
                cnt++;
            }
        }
        for (int i = cnt; i < nums.size(); i++) {
            nums.at(i) = 0;
        }
    }
};
```