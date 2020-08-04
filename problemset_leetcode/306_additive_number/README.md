## leetcode306 累加数

### 思路
```
dfs深度优先遍历，需要确定3个idx：i,j,k,string 1 = s[i, j), string 2 = s[j,k), string 3 = s[k,size),其中size = string 1 + string 2后结果的长度
则递归遍历，找出符合条件的情况，注意遇到如下情况可以直接退出当前次的搜索：
1.string 1 的第一个数为0，并且string 1 长度大于1
2.string 2 的第一个数为0，并且string 2 长度大于1
3.string 3 超出s的限制
4.string 3 和sum不一样
满足要求的情况：
string 3 和 sum一样，并且已经到达s的最后
```

### code
```c++
    class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1Size = num1.size();
        int num2Size = num2.size();
        int i = num1Size - 1, j = num2Size - 1, tmp = 0, carry = 0;
        string ans;
        while(i >= 0 && j >= 0) {
            tmp = num1[i--] - '0' + num2[j--] - '0' + carry;
            if (tmp >= 10) {
                tmp = tmp - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans += (tmp + '0');
        }
        if (i >= 0) {
            while(i >= 0) {
                tmp = num1[i--] - '0' + carry;
                if(tmp >= 10) {
                    tmp = tmp - 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                ans += (tmp + '0');
            }
        }
        if (j >= 0) {
            while (j >= 0) {
                tmp = num2[j--] - '0' + carry;
                if(tmp >= 10) {
                    tmp = tmp - 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                ans += (tmp + '0');
            }
        }
        if(carry == 1) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool dfs(string& s, int i, int j, int k) {
        if((s[i] == '0' && j - i > 1) || (s[j] == '0' && k - j > 1)) {
            return false;
        }
        string a = s.substr(i, j - i);
        string b = s.substr(j, k - j);
        string sum = addStrings(a, b);
        int size = sum.size();
        string c = s.substr(k, size);
        if ((k + size > s.size()) || (sum != c)) {
            return false;
        }
        if ((k + size == s.size())) { // sum == c
            return true;
        }
        return dfs(s, j, k, k + size);
    }

    bool isAdditiveNumber(string num) {
        int i = 0;
        for(int j = i + 1; j < num.size(); j++) {
            for (int k = j + 1; k < num.size(); k++) {
                if (dfs(num, i, j, k)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```