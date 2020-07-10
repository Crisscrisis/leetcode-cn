## leetcode42 接雨水

### 思路
```
对于每个位置来说，当前位置能装的水，就等于他左边能看到最高高度，和右边能看到最高高度之中最小的那个形成的水位，和他本身的差值。
使用带备忘录的遍历，先计算出对于每个位置的柱子来说，他左边的最高柱子的高度（包括它本身，目的是为了防止出现左边没有比他高的柱子，则算出的是负值），再计算出对于每个诶诶之的柱子来说，他右边的最高柱子的高度（包括本身，同理），最后遍历一遍，计算出对于每个位置来说，能装的水。

```

### code
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        vector<int> lmax(height.size()), rmax(height.size());
        int water = 0;
        lmax.at(0) = height.at(0);
        rmax.at(height.size() - 1) = height.at(height.size() - 1);
        for (int l = 1; l < height.size(); l++) {
            lmax.at(l) = max(height.at(l), lmax.at(l-1));
        }
        for (int r = height.size() - 2; r >= 0; r--) {
            rmax.at(r) = max(height.at(r), rmax.at(r+1));
        }
        for(int i = 0; i < height.size(); i++) {
            water += min(lmax.at(i), rmax.at(i)) - height.at(i);
        }
        return water;
    }
};
```