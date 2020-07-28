## leetcode125 验证回问串

### 思路
```
双指针法，左右分别遍历，如果左/右为非法输入，则另一边的指针需要回退一个。
isalnum：相当于isalpha(c)||isdigit(c)，判断是否为字母或数字
tolower：转换为小写
toupper：转换为大写

```

### code
```c++
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) {
            return true;
        }
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            if (!isalnum(s[l])) {
                r++;
                continue;
            } else if (!isalnum(s[r])) {
                l--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
        }
        return true;
    }
};
```