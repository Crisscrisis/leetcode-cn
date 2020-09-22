## leetcode 90 子集2

### 思路
```
使用begin，对同层已经使用过的元素，在同层其他分支里不再使用。
使用visited，排除重复访问的元素
```

### code
```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> visited;
    void dfs(vector<int>& cur, int begin, int len, vector<int>& nums) {
        if (len > nums.size()) {
            return;
        }
        ans.push_back(cur);
        for (int i = begin; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == 0) {
                continue;
            }
            if (visited[i] == 0) {
                cur.push_back(nums[i]);
                visited[i] = 1;
                dfs(cur, i + 1, len + 1, nums);
                cur.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<int> cur;
        visited.resize(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(cur, 0, 0, nums);
        return ans;
    }
};
```