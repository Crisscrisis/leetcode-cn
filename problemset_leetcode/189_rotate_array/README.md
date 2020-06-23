## leetcode189 旋转数组

### 思路
```
循环替换，从第一个idx开始，他要到达的下一个位置是(idx+k)%len，则在下一个位置上的元素被挤出来，那个元素再找他的下一个位置...以此类推，直到挪动的次数等于len结束。需要注意特殊情况：如果挪动是在部分几个元素中循环进行，则需要退出，给起始位置加一，进行下一次循环
```

### code
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) {
            return;
        }
        int len = nums.size();
        k = k % len;
        int start = 0;
        int tmp = 0;
        for (int cnt = 0; cnt < len; start++) {
            int current = start;
            int pre = nums.at(current);
            do {
                int next = (current + k) % len;
                int tmp = nums.at(next);
                nums.at(next) = pre;
                current = next;
                pre = tmp;
                cnt++;
            } while (current != start);
        }
    }
};
```