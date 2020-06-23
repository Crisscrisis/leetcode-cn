## leetcode26 删除排序数组中的重复项

### 思路
```
快慢指针，一个指针i用于遍历整个数组，另一个指针j用于指向待存入的位置，当i当前值的值和i-1不同时，则存入，i，j均+1，否则，i+1，j不变
```

### code
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        int ans = 1;
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i-1) != nums.at(i)) {
                nums.at(j++) = nums.at(i);
                ans++;
            }
        }
        return ans;
    }
};
```