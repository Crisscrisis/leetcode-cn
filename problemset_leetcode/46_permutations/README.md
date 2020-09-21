## leetcode46 全排列

### 思路
```
首先遍历数组 nums的全排列，需要保证，字符串s中的第i个字符，在这次递归前使用了，则他的分支就不能再使用s[i]，而下次递归前可以用。
由于输入不包含重复数字，则无需做去重操作。
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

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        visited.resize(nums.size(), 0);
        travel(tmp, 0, nums);
        return ans;
    }
};
```