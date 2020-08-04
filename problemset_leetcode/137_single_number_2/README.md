## leetcode137 只出现一次的数字 2

### 思路
```
hash map方法：构造一个hash map，键为数组中的数字，值为出现的次数，统计一次之后，遍历，将出现次数为1的取出，即为结果。
bit 操作：构造一个长度为32的数组，每个数组存储的是相应二进制位为1的个数，则3个相同的数，给任意一位贡献一定是3，则遍历之后，给该数组中每一位%3，得到的余数即为那个唯一不同的数的相应位的值。
```

### code
```c++
class Solution {
public:
#if 0
    // hash map
    int singleNumber(vector<int>& nums) {
        map<int, int> maps;
        for (auto num: nums){
            if(maps.find(num) == maps.end()) {
                maps.insert({num, 1});
            } else {
                maps.at(num) += 1;
            }
        }
        for (auto num:nums) {
            if(maps.at(num) == 1) {
                return num;
            }
        }
        return 0;
    }

    // bit manipulation
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (auto num: nums) {
                if ((num >> i) & 1 == 1) {
                    cnt++;
                }
            }
            if (cnt % 3 != 0) {
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
#endif
    // bit manipulation 2
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        int ans = 0;
        for (auto num: nums) {
            for (int i = 0; i < 32; i++) {
                bits[i] += (num >> i) & 1;
            }
        }
        for (int i = 0; i < 32; i++) {
            ans = ans | ((bits[i] % 3) << i);
        }
        return ans;
    }
};
```