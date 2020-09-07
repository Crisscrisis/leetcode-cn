## leetcode88 合并两个有序数组

### 思路
```
简单粗暴方法：先合并，再排序
```

### code
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j = 0;
        for (i = m; i < nums1.size(); i++) {
            nums1.at(i) = nums2.at(j++);
        }
        sort(nums1.begin(), nums1.end());
    }
};
```