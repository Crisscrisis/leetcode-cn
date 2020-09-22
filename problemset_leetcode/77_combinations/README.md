## leetcode77 组合

### 思路
```
由于不能包含重复，则当前层若使用了元素a，同一层的其他分支则不能使用元素a，故需要begin参数。
```

### code
```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> visited;
    void dfs(vector<int>& cur, int n, int k, int begin, int len) {
        if (len == k) {
            ans.push_back(cur);
            return;
        }
        if (len > k) {
            return;
        }
        for (int i = begin; i <= n; i++) {
            cur.push_back(i);
            dfs(cur, n, k, i + 1, len + 1);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        if (n == 0) {
            return ans;
        }
        vector<int> cur;
        dfs(cur, n, k, 1, 0);
        return ans;
    }
};
```