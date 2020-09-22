## leetcode78 子集

### 思路
```
为了避免重复，同一层使用过的元素，则同层其他分支不再使用，故使用begin标识。
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
            cur.push_back(nums[i]);
            dfs(cur, i + 1, len + 1, nums);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<int> cur;
        dfs(cur, 0, 0, nums);
        return ans;
    }
};
```