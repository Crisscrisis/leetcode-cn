## leetcode645 错误的集合

### 思路
```
首先，除了输入数组之外，再构建一个1---n的数组nums2，则nums中，包含：1,2,...,dup,dup，而nums2中包含：1,2,...,dup,miss，
遍历这两个数组进行异或操作，则重复两次的数都被过滤掉，剩下的结果即为dup^miss，
则随便取一位为1的，对nums和nums2组成的数组进行过滤，分出来两组，一组包含dup，和其余n对其他数，另一组包含miss，和其余n对其他数，
分别对这两组数进行异或操作，则最终能过滤出来dup和miss，
还需要遍历判断一下，哪个是dup，哪个是miss。
```

### code
```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dupMiss = 0; // dup ^ miss
        vector<int> wholeNums;
        int a = 0, b = 0;
        for (int num: nums) {
            dupMiss = dupMiss ^ num;
            wholeNums.push_back(num);
        }
        for (int i = 0; i < nums.size(); i ++) {
            dupMiss = dupMiss ^ (i + 1);
            wholeNums.push_back(i + 1);
        }
        int div = 1;
        while((div & dupMiss) == 0) {
            div = div << 1;
        }

        for (int num: wholeNums) {
            if ((num & div) == 0) {
                a = a ^ num;
            } else {
                b = b ^ num;
            }
        }
        for (int num: nums) {
            if(num == a) {
                return {a, b};
            }
        }
        return {b, a};
    }
};
```