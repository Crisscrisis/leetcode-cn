## leetcode3 无重复字符的最长子串

### 思路
```
用unordered set来存储子串内容，设置滑动窗口，从最左边开始滑动，如果当前新的字符在子串内，则需要从左边开始一次往右删除子串中的元素，直到当前新的字符不在子串内，然后比较当前长度跟最大长度的大小，留下大的那个值

```

### code
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        unordered_set<char> subStr;
        int maxLen = 0;
        int left = 0;
        for(int i = 0; i < s.length(); i++) {
            while (subStr.find(s.at(i)) != subStr.end()) {
                subStr.erase(s.at(left));
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
            subStr.insert(s.at(i));
        }
        return maxLen;
    }
};
```