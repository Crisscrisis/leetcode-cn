## leetcode747 至少是其他数字两倍的最大数

### 思路
```
先按大小进行排序，如果最大的至少是第二大的两倍，则满足条件，注意排序之前，要将每个数转换为数值+原始idx的结构体，sort依据的是数值。
```

### code
```c++
typedef struct
{
    int x, y;
} Point;
bool cmp(Point a, Point b)
{
    return a.y > b.y;
}
class Solution {
public:

    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        vector<Point> numsVec(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numsVec.at(i).x = i;
            numsVec.at(i).y = nums.at(i);
        }
        sort(numsVec.begin(), numsVec.end(), cmp);
        if (numsVec.at(0).y >= numsVec.at(1).y * 2) {
            return numsVec.at(0).x;
        }
        else {
            return -1;
        }
    }
};
```