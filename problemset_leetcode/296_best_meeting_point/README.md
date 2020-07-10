## leetcode296 最佳的碰头地点

### 思路
```
从距离公式distance(p1, p2)=|p2.x - p1.x| + |p2.y - p1.y|可以发现，最终的距离等于两部分相加，这两部分的计算是独立的，不相关的，故可以分别转换为两个1维问题，计算出x和y两个维度的距离。具体做法：
1.遍历所有位置，用两个vectro记录下来每个人的位置点的x，y坐标；
2.对于每个vector，排序使其保证为升序（上下记录行数的不需要排序，因为遍历是已经是升序），然后分别求出每个vector中所有点距离中点的距离。
3.将两个维度的距离相加

```

### code
```c++
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<vector<int>> people;
        vector<int> row, col;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(0).size(); j++) {
                if (grid.at(i).at(j) == 1) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        sort(col.begin(), col.end());
        int dis_x, dis_y, p, q;
        p = 0;
        q = row.size();
        dis_y = row.at(q-- - 1) - row.at(p++);
        while (p < q) {
            dis_y += row.at(q-- - 1) - row.at(p++);
        }
        p = 0;
        q = col.size();
        dis_x = col.at(q-- - 1) - col.at(p++);
        while (p < q) {
            dis_x += col.at(q-- - 1) - col.at(p++);
        }
        return dis_x + dis_y;
    }
};
```