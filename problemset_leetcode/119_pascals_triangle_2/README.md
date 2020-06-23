## leetcode119 杨辉三角2

### 思路
```
输入的rowIdex为i，则实际取得的是杨辉三角的第i+1行(因为i是从0开始的)，且输出的数组长度也为i+1。则需要计算i+1次，每次只需要计算除去两头之外的值，每个值依赖的是上一行的两个值，即ans[j] = ans[j] + ans[j-1]，因为每次修改的值所依赖的是上一行中它本身位置和它本身位置之前的值，故需要后向前计算，否则会影响到下一个元素的计算。
```

### code
```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            vector<int> ans;
            return ans;
        }
        vector<int> ans(rowIndex + 1);
        if (rowIndex == 0) {
            ans.at(0) = 1;
            return ans;
        }
        if (rowIndex == 1) {
            ans.at(0) = 1;
            ans.at(1) = 1;
            return ans;
        }
        for (int i = 0; i <= rowIndex; i++) {
            ans[i] = 1;
            for (int j = i; j > 1; j--) {
                ans[j-1] = ans[j-2] + ans[j-1];
            }
        }
        return ans;
    }
};
```