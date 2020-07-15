## leetcode11 盛最多水的容器

### 思路
```
双指针法，每次都选择将短的那个板向内测移动。因为向内移动长板，一定不能使新的短板变长，而向内移动短板，有可能使新的短板变长。

```

### code
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l, r, width, minIdx;
        l = 0;
        r = height.size() - 1;
        int maxArea = 0;
        while(l < r) {
            if (height.at(l) < height.at(r)) {
                width = r - l;
                maxArea = max(maxArea, height.at(l) * width);
                l++;
            } else {
                width = r - l;
                maxArea = max(maxArea, height.at(r) * width);
                r--;
            }
        }
        return maxArea;
    }
};
```