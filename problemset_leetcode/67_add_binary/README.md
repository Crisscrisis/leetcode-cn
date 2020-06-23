## leetcode67 二进制求和

### 思路
```
模拟竖式加法，a和b相加，
1.先增加最低位，即有四种情况：0+0;0+1;1+0;1+1,每种情况下，还需要考虑是否进位。而且每位相加之后，进位carry标识也会更新；
2.按照之前的规则遍历，a和b可能有一个数先遍历完，则另一个数的每位，也有两种情况：1；0，也需要把前一位的进位考虑进来，每一位处理完，也需要更新carry；
3.最终a和b都遍历完之后，还需要判断carry，若还保存有carry，则需要在最高位再增加1，否则结束。
```

### code
```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen = b.size();
        string ans{};
        bool carry = false;
        while(!a.empty() && !b.empty()) {
            if (a.back() == '0' && b.back() == '0') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = false;
                }
            }
            if ((a.back() == '0' && b.back() == '1') || (a.back() == '1' && b.back() == '0')) {
                if (carry) {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                }
            }
            if (a.back() == '1' && b.back() == '1') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                }
            }
            a.pop_back();
            b.pop_back();
        }
        while (!a.empty()) {
            if (a.back() == '0') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = false;
                }
            }
            if (a.back() == '1') {
                if (carry) {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                }
            }
            a.pop_back();
        }
        while (!b.empty()) {
            if (b.back() == '0') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = false;
                }
            }
            if (b.back() == '1') {
                if (carry) {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                }
            }
            b.pop_back();
        }
        if (carry) {
            ans.insert(ans.begin(), '1');
        }
        return ans;
    }
};
```