## leetcode 84 柱状图中最大的矩形

### 思路
```
给传入数组前后增加两个为0的哨兵，方便迭代。
保存一个单调栈，里面存的是传入数组的下标，且单调栈里的下标指向的元素，为严格单调递增的。
如果当前元素大于等于栈顶所指的元素，则还无法确定以栈顶所指元素为高度的，包含栈顶的最大矩形面积，故继续入栈；
如果档期那元素严格小于栈顶所指元素，则可以确定以栈顶所指元素为高度，包含栈顶的最大矩形面积，一定在栈顶所指元素的左侧（包含栈顶所指元素）。故此时将栈顶语元素记录，计算面积，出栈，与最大面积比较。
```

### code
```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // insert Sentinel to 2 sides of input vector
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        
        deque<int> stk;
        int maxArea = 0; 
        for(int i = 0; i < heights.size(); i++) {
            // stack top is strictly smaller than current
            while(!stk.empty() && heights[stk.back()] > heights[i]) {
                int cur = stk.back();
                stk.pop_back();
                int left = stk.back();
                int right = i - 1;
                // max area of the current height in from position [0,cur]
                int tmpArea = (right - left) * heights[cur];
                maxArea = max(maxArea, tmpArea);
            }
            // stack top is euqal or larger to current
            stk.emplace_back(i);
        }
        return maxArea;
    }
};
```