## leetcode260 只出现一次的数字 3

### 思路
```
先全部遍历一次做异或，则留下来的结果即为两个只出现一次的数字a，b的异或。
找到这个结果第一个1，以此为mask，比较整个数组，会将整个数组分为两组，一组包含a和其他n对相同的数字，另一组包含b和其他n对相同的数字。
这两组分别内部遍历做异或，则会留下来a和b。
```

### code
```c++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int dif = 0, a = 0, b = 0;
        for(int num: nums) {
            dif = dif ^ num;
        }
        int div = 1;
        while ((div & dif) == 0) {
            div = div << 1;
        }
        for(int num: nums) {
            if((num & div) == 0) {
                a = a ^ num;
            } else {
                b = b ^ num;
            }
        }
        return {a, b};

    }
};
```