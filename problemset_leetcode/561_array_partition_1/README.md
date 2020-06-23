## leetcode561 数组拆分

### 思路
```
使用数学思想，先将该数组sort变为从小到大排列的数组，然后可以发现，要实现最大的总和，取的必然是第1,3,5,7...奇数个数，分别跟第2,4,6,8...偶数个数作为组合。
证明：对于一个升序数组[n1,n2,...n2m-1,n2m],选第一对min(x,y)时，必然会“牺牲掉”n2m，也就是说n2m必然是作为min(x,y)中较大的那个，那么此时最佳策略就是拿出其余数组中最大的和其搭配，也就是选择n2m-1，那这一对min(x,y)留下的最大值就是n2m-1。剩下的数组，按照相同的方法，以此类推，则最终选出的就是升序数组的奇数个元素
```

### code
```c++
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; 2 * i < nums.size(); i++) {
            ans += nums.at(2 * i);
        }
        return ans;
    }
};
```