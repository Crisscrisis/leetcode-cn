## leetcode54 螺旋矩阵

### 思路
```
考察每一轮迭代的移动方向为：右，下，左，上，朝这四个方向移动均有一个起点和终点的index的limit，朝右移动到limit位置之后，则上侧limit被更新（加一）；接着朝下移动到limit位置后，右侧limit被更新（减一）；接着朝左移动到limit位置后，下侧limit被更新（减一）；接着朝上移动到limit位置后，左侧limit被更新（加一）；更新完limit值之后，如果左右limit交叉，或上下limit交叉，则退出。
```

### code
```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix.at(0).size() - 1;
        while(true) {
            // right
            for (int k = left; k <= right; k++) {
                ans.push_back(matrix.at(up).at(k));
            }
            if (++up > down) {
                break;
            }

            // down
            for (int k = up; k <= down; k++) {
                ans.push_back(matrix.at(k).at(right));
            }
            if (--right < left) {
                break;
            }

            // left
            for (int k = right; k >= left; k--) {
                ans.push_back(matrix.at(down).at(k));
            }
            if (--down < up) {
                break;
            }

            // up
            for (int k = down; k >= up; k--) {
                ans.push_back(matrix.at(k).at(left));
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
};
```