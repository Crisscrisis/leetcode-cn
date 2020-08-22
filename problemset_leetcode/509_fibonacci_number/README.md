## leetcode509 斐波那契数

### 思路
```
设置一个向量保存已经计算好的fib数，注意：初始化时，为避免引起歧义导致编译失败，可以利用vector赋值构造函数
（详见<https://blog.csdn.net/m0_47696151/article/details/107367876>）
```

### code
```c++
class Solution {
public:
    vector<int> fib_vec = vector<int> (31,0);
    int fib(int N) {
        if(N == 0) {
            fib_vec[0] = 0;
            return fib_vec[N];
        }
        if(N == 1) {
            fib_vec[1] = 1;
            return fib_vec[N];
        }
        if(fib_vec[N] != 0) {
            return fib_vec[N];
        } else {
            fib_vec[N] = fib(N -1) + fib(N - 2);
        }
        return fib_vec[N];
    }
};
```