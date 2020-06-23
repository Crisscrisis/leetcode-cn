## leetcode557 反转字符串中的单词3

### 思路
```
逐个解析s，没遇到一个单词，则执行反转模块，需要begin，end来记录单词的首尾，需要考虑最后一个单词的特殊条件
```

### code
```c++
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            string ans;
            return ans;
        }
        int begin = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == ' ') {
                while (begin < end){
                    char tmp = s.at(begin);
                    s.at(begin) = s.at(end);
                    s.at(end) = tmp;
                    begin++;
                    end--;
                }
                begin = i + 1;
            } else {
                end = i;
            }
        }
        if (s.at(s.size() - 1) != ' '){
            while (begin < end){
                    char tmp = s.at(begin);
                    s.at(begin) = s.at(end);
                    s.at(end) = tmp;
                    begin++;
                    end--;
                }
        }
        return s;
    }
};
```