## leetcode415 字符串相加

### 思路
```
按位相加，注意考虑进位情况，以及一个string比另一个string长的情况。
```

### code
```c++
lass Solution {
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
};
```