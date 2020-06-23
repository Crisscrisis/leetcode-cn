## leetcode14 最长公共前缀

### 思路
```
先将字符串数组数组用sort排序，排好序之后，该字符串数组变为字典序，则要找最长公共前缀，只需要找字典序的数组中的第一个字符串和最后一个字符串的公共前缀，即为最长公共前缀
```

### code
```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.empty()) {
            return ans;
        }
        sort(strs.begin(),strs.end());
        if (strs.at(0).empty()) {
            return ans;
        }
        int n = strs.size();
        int i = 0;
        for (i = 0; i < strs.at(0).size(); i++) {
            if (strs.at(0).at(i) != strs.at(n-1).at(i)) {
                return strs.at(0).substr(0,i);
            }
        }
        if (i == strs.at(0).size()) {
            return strs.at(0);
        }
        return ans;
    }
};
```