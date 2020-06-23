## leetcode344 反转字符串

### 思路
```
使用双指针，分别从前后朝中间方向走，每次交换两个指针所指的空间内容，停止条件：left>=right
```

### code
```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin, end;
        if (s.empty()) {
            return;
        }
        begin = 0;
        end = s.size() - 1;
        while(begin < end) {
            swap(s.at(begin++), s.at(end--));
        }
    }
};
```