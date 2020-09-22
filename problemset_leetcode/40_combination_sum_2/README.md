## leetcode40 组合总和2

### 思路
```
需要记录哪些元素已经用过，不能重复使用，故需要用visited数组。
搜索时，可以剪枝，如果同层已经用过该元素，则同层的其他搜索，不需要再用该元素，故用begin索引。
```

### code
```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> visited;
    void travel(vector<int>& cur, int sum, int begin, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            if (i > 0 && candidates[i - 1] == candidates[i] && visited[i - 1] == 0) {
                continue;
            }
            if (visited[i] == 0) {
                cur.push_back(candidates.at(i));
                visited[i] = 1;
                travel(cur, sum + cur.back(), i, target, candidates);
                cur.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        visited.resize(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        travel(cur, 0, 0, target, candidates);
        return ans;
    }
};
```