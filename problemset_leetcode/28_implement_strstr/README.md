## leetcode28 实现strStr()

### 思路
```
遍历被匹配的string haystack，如果第一个字符相等，则遍历下一个，如果遍历完之后，发现正好到达needle的末尾，则说明匹配上，则退出。需要考虑多种边界条件以及多种特殊情况：
1.haystack和needle长度为1
2.haystack长度小于needle
3.haystack或needle为空
```

### code
```c++
class Solution {
public:
    class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty() || haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            int k = i;
            int j = 0;
            while ( k < haystack.size() && j < needle.size() && haystack.at(k) == needle.at(j) ) {
                k++;
                j++;
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};
```