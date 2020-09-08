## leetcode20 有效的括号

### 思路
```
用一个栈来存储做括号，如果遇到右括号，则判断栈顶，如果符合，则pop，继续；如果不符合，则直接返回false
最终遍历完之后，如果栈内没有剩下的左括号，则返回true，否则返回false
```

### code
```c++
class Solution {
public:
    bool isMatch(char s, char pa) {
        if (pa == '(') {
            if (s == ')') {
                return true;
            } else {
                return false;
            }
        } else if (pa == '{') {
            if (s == '}') {
                return true;
            } else {
                return false;
            }
        } else if (pa == '[') {
            if (s == ']') {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    bool isValid(string s) {
        deque<char> parentheses(1);
        if (s.empty()) {
            return true;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                parentheses.push_back(s[i]);
            } else {
                bool ans = isMatch(s[i], parentheses.back());
                if (ans) {
                    parentheses.pop_back();
                } else {
                    return false;
                }
            }
        }
        if(parentheses.size() == 1) {
            return true;
        }
        return false;
    }
};
```