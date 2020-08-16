## leetcode5 最长回文子串

### 思路
```
动态规划，核心状态转移：
假设dp[i][j]是s[i]到s[j]的左闭右闭区间的字符串，是否为回文，则有
若s[i]!=s[j]，则dp[i][j] = 0;
若s[i]==s[j]，则：
    dp[i][j] = dp[i+1][j-1], if j - i > 2;
    dp[i][j] = 1, if j - i < 2;
```

### code
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        int len = s.length();
        int dp[500][500]; // 1000 is good for leetcode debugger, but will cause stack overflow fault in visual studio debug
        int front = 0;
        int tail = 0;
        int maxLen = 0;
        int i, j;
        for (i = 0; i < len; i++) {
            dp[i][i] = 1;
        }
        for (j = 1; j < len; j++) {
            for (i = 0; i < j; i++) {
                if(s.at(i) != s.at(j)) {
                    dp[i][j] = 0;
                } else {
                    if (j - i < 2) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if (dp[i][j] == 1 && ((j - i + 1) > maxLen)) {
                        maxLen = j - i + 1;
                        front = i;
                    }
                }
            }
        }
        if(maxLen == 0) {
            return s.substr(0, 1);
        }
        return s.substr(front, maxLen);
    }
};
```