## leetcode498 对角线遍历

### 思路
```
观察一个对角线矩阵：
matrix[3][4] =
[
[1, 2,  3,  4 ],
[5, 6,  7,  8 ],
[9, 10, 11, 12]
]

可以发现如下规律：
1.对角线遍历的本质就是先在对该矩阵做分割，每次遍历从左往右取分割的一条线上的所有元素；
2.第k次遍历，所取一条线上的元素a[i][j]满足：i+j=k-1
3.k和row，col有如下关系：k=row+col-1
4.i和j还需要满足条件：0<i<row,0<j<col
5.每次遍历有两个方向：i从0增长的方向，i从最大值减少的方向，当遍历次数为2,4,6,8...时，遍历方向为i从0增长方向；当遍历次数为1,3,5,7...时，遍历方向为i从最大值减少方向
```

### code
```c++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        // 如果输入矩阵为空矩阵，则直接退出空矩阵
        if (row == 0) {
            vector<int> ans;
            return ans;
        }
        int col = matrix.at(0).size();
        vector<int> ans;
        int sums = row + col - 2;
        int cnt = 0; // 遍历次数记录
        for (int sum = 0; sum <= sums; sum++) {
            vector<int> tmp; // 临时vector，存储此次遍历行的所有元素
            for (int i = 0; i < row; i++) {
                // i + j = sum
                int j = sum - i;
                if (j < col && j >= 0) {
                    // 有效的元素，存入该遍历行中
                    tmp.push_back(matrix[i][j]);
                }
            }
            cnt++;
            // 如果为奇数次遍历，则需要反转方向，如果为偶数次遍历，则按顺序输出
            if (cnt % 2 == 1) {
                reverse(tmp.begin(), tmp.end());
            }
            for (int n = 0; n < tmp.size(); n++) {
                ans.push_back(tmp.at(n));
            }
        }
        return ans;
    }
};
```