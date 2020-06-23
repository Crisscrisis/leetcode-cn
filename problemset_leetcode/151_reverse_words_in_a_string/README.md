## leetcode151 翻转字符串里的单词

### 思路
```
首先先将s中的单词一个一个解析出来，存入一个stack中，然后再逐个pop出stack，将其append到答案string中，需要考虑s为空，或空格的特殊情况
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
        stack<string> words;
        string currWord;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == ' ') {
                if (!currWord.empty()) {
                    words.push(currWord);
                    currWord = {};
                }
            } else {
                currWord.push_back(s.at(i));
            }
        }
        if (!currWord.empty()) {
            words.push(currWord);
        }
        string ans;
        if (words.empty()) {
            return ans;
        }
        int wordsNum = words.size();
        for (int i = 0; i < wordsNum - 1; i++) {
            ans.append(words.top());
            ans.append(" ");
            words.pop();
        }
        ans.append(words.top());
        return ans;
    }
};
```