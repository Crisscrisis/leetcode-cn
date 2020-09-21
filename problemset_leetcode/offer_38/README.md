## leetcode38 字符串的排列

### 思路
```
首先遍历字符串s的全排列，需要保证，字符串s中的第i个字符，在这次递归前使用了，则他的分支就不能再使用s[i]，而下次递归前可以用。
为了保证输出结果没有重复元素，可以使用两种方法：
1.使用set保存结果，set天然去重，最后再把set转换为vector
2.使用vector保存结果，之后使用sort(vec.begin(), vec.end()),vec.erase(unique(vec.begin(), vec.end()), vec.end())去重

```

### code
```c++
class Solution {
public:
    vector<string> ans;
    // set<string> setAns;
    vector<int> visited;
    void travel(string str, int idx, string org) {
        if (idx == org.size()) {
            // setAns.insert(str);
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < org.size(); i++) {
            if (visited[i] == 0) {
                str.push_back(org.at(i));
                visited[i] = 1;
                travel(str, idx + 1, org);
                str.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<string> permutation(string s) {
        visited.resize(s.size(), 0);
        travel("", 0, s);
        // vector<string> ans(setAns.begin(), setAns.end());
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
```