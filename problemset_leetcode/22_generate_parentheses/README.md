## leetcode22 括号生成

### 思路
```
标准递归写法，注意，每次添加新括号的条件：对于左括号，左括号数量<n即可；
对于右括号，右括号数量<左括号数量，且右括号数量<n；
结束此次生成条件：左括号数量=右括号数量=n
```

### code
```c++
class Solution {
public:
    void generate(int left, int right, int max, vector<string>& str, string tmpstr) {
        // terminator
        if (left < right || left > max || right > max) {
            return;
        }
        if ( left == max && right == max ) {
            str.push_back(tmpstr);
            return;
        }

        // process current logic
        string s1 = tmpstr + "(";
        string s2 = tmpstr + ")";

        // drill down
        generate(left + 1, right, max, str, s1);
        generate(left, right + 1, max, str, s2);

        // restore current status
    }

    vector<string> generateParenthesis(int n) {
        vector<string> str;
        generate(0, 0, n, str, "");
        return str;
    }
};
```