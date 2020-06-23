## leetcode27 移除元素

### 思路
```
用了两个指针，一个指针j用于遍历原始数组，另一个指针i用于遍历“待存入”的位置，两个指针均从0向后移动，只有当j指向的元素不等于target时，才将其存入i指向的“待存入”位置，否则，j指向下一个，i不动，这样j就比i快或至少和气相等，最终遍历完整个数组，将后面多余的数组删掉。
```

### code
```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int ans = nums.size();
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            else {
                ans--;
            }
        }
        while (nums.size() != ans) {
            nums.pop_back();
        }
        return ans;
    }
};
```