## leetcode66 加一

### 思路
```
模拟竖式加一，从个位开始，加一之后，对其进行模10运算，如果为0，则说明产生进位，再对高一位进行加一运算。如果加到最高位还是为0，则说明最高位原本为9，加1之后多了一位，则可以直接生成一个新的100..0的数组作为输出。
```

### code
```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        vector<int> ans(digits.size() + 1);
        ans.at(0) = 1;
        return ans;
    }
};
```