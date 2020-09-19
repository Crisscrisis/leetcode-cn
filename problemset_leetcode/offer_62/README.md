## leetcode62 圆圈中最后剩下的数字

### 思路
```
逆推法：设f(n, m)为n个数字，每次去掉第m个数字时，最终剩下的数字下标
则n = 1时，显然下标为0， n = n时，下标为 (f(n-1, m) + m)%n
f(1, m) = 0
f(2, m) = (f(1, m) + m)%2
f(n, m) = (f(n-1, m) + m)%n
```

### code
```c++
class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        for (int i = 2; i <= n; i++) {
            pos = (pos + m) % i;
        }
        return pos;
    }
};
```