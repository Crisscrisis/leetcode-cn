## leetcode4 寻找两个正序数组的中位数

### 思路
```
O(m+n)解法：由于是两个有序数组，故遍历一遍，将两个有序数组合并为一个数组，然后直接从新的数组中找到中位数即可
O(log(m+n))解法：
```

### code
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergeList;
        int p = 0;
        int q = 0;
        while (p < nums1.size() && q < nums2.size()) {
            if (nums1.at(p) < nums2.at(q)) {
                mergeList.push_back(nums1.at(p));
                p++;
            } else {
                mergeList.push_back(nums2.at(q));
                q++;
            }
        }
        if (p < nums1.size()) {
            while (p < nums1.size()) {
                mergeList.push_back(nums1.at(p));
                p++;
            }
        }
        if (q < nums2.size()) {
            while (q < nums2.size()) {
                mergeList.push_back(nums2.at(q));
                q++;
            }
        }
        int len = mergeList.size();
        if (len % 2 == 1) {
            return mergeList.at(len / 2);
        } else {
            return double((mergeList.at(len / 2) + mergeList.at(len / 2 - 1))) / 2;
        }
    }
};
```