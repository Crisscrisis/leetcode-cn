## leetcode39 组合总和

### 思路
```
由于不讲究顺序，则搜索的时候，对于每一层来说，每一层不需要重复搜索，即在同一层，搜索完一个元素之后，同层的其他搜索，不需要再搜索这个元素。
什么时候使用 used 数组，什么时候使用 begin 变量
排列问题，讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为不同列表时），需要记录哪些数字已经使用过，此时用 used 数组；
组合问题，不讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为相同列表时），需要按照某种顺序搜索，此时使用 begin 变量。
```

### code
```c++
class Solution {
public:
    vector<vector<int>> ans;
    void travel(vector<int>& cur, int sum, int begin, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            cur.push_back(candidates.at(i));
            travel(cur, sum + cur.back(), i, target, candidates);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        travel(cur, 0, 0, target, candidates);
        return ans;
    }
};
```