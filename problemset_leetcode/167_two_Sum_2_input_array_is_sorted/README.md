## leetcode167 两数之和2-输入有序数组

### 思路
```
前后双指针分别指向头和尾，计算其指向的两个元素之和，如果等于target，则直接输出；如果小于target，则需要更大一点，头指针向后移动一位；如果大于target，则需要更小一点，尾指针向前移动一位
```

### code
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        if (numbers.empty() || numbers.size() == 0) {
            return ans;
        }
        int begin = 0;
        int end = numbers.size() - 1;
        int sum = numbers.at(begin) + numbers.at(end);
        while( sum != target && begin < end) {
            if (sum < target) {
                begin++;
                sum = numbers.at(begin) + numbers.at(end);
            } else {
                end--;
                sum = numbers.at(begin) + numbers.at(end);
            }
        }
        if (sum == target) {
            ans.push_back(++begin);
            ans.push_back(++end);
            return ans;
        } else {
            return ans;
        }
    }
};
```