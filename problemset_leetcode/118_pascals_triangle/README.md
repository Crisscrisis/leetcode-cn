## leetcode118 杨辉三角

### 思路
```
观察规律，发现除了第一行较特殊外，其余行有如下规律：
1.每行的第一个元素，和最后一个元素为1
2.第i行的中间元素j（非第一个和最后一个），满足matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j]
```

### code
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if (numRows == 0) {
            return ans;
        }
        ans.at(0).push_back(1);
        for (int i = 1; i < numRows; i++) {
            ans.at(i).push_back(1);
            for (int j = 1; j < i; j++) {
                ans.at(i).push_back(ans.at(i-1).at(j - 1) + ans.at(i-1).at(j));
            }
            ans.at(i).push_back(1);
        }
        return ans;
    }
};
```