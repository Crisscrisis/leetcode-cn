## leetcode47 全排列 2

### 思路
```
首先遍历数组 nums的全排列，需要保证，字符串s中的第i个字符，在这次递归前使用了，则他的分支就不能再使用s[i]，而下次递归前可以用。
对于去重，需要首先sort一下初始数组。然后增加一个判断条件：如果同意树层使用过，则跳过。这样可以有效剪枝。
```

### code
```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> visited;
    void travel(vector<int>& cur, int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 这里理解visited[i - 1]非常重要
            // visited[i - 1] == true，说明同一树支nums[i - 1]使用过
            // visited[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && visited[i-1] == 0) {
                continue;
            }
            if (visited[i] == 0) {
                cur.push_back(nums.at(i));
                visited[i] = 1;
                travel(cur, idx + 1, nums);
                cur.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        visited.resize(nums.size(), 0);
        travel(tmp, 0, nums);
        return ans;
    }
};
```