## leetcode1 两数之和

### 思路
```
最优算法为hash map，可以将nums[i],i作为key和value存入hash map，遍历所有nums[i]，则问题可以转化为：在hashmap中存在target-nums[i]的key
如果找到，对应的value就是下标，需要注意，找到对应返回的下标，不能等于它本身，因为同一个成员不能用两次
```

### code
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            numsMap.insert({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++) {
            if (numsMap.find(target - nums[i]) != numsMap.end()) {
                if (i != numsMap[target - nums[i]]) {
                    ans.push_back(min(i, numsMap[target - nums[i]]));
                    ans.push_back(max(i, numsMap[target - nums[i]]));
                    return ans;
                }
            }
        }
        return ans;
    }
};
```