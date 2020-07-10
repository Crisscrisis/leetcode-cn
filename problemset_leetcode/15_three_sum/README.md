## leetcode15 三数之和

### 思路
```
先对数组进行排序，然后从第一个元素开始遍历，从左到右分别是i，lo，hi，如果三个数之和等于0，则将其加入。
注意：以下情况需要跳过，避免重复：
1.如果当前的值nums[i] == nums[i-1]，则需要跳过，以避免重复
2.当和相等时，如果nums[lo] == nums[lo+1]，或者nums[hi] == nums[hi-1]，则需要跳到下一个，避免重复
可以剪枝的情况：
1.如果最小的值nums[i]已经大于0了，则之后的值只可能更大，则直接退出即可

```

### code
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) {
            return ans;
        }
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if (nums.at(i) > 0) {
                return ans;
            }
            if (i > 0 && nums.at(i) == nums.at(i-1)) {
                continue;
            }
            int lo = i + 1;
            int hi = nums.size() - 1;
            while(lo < hi) {
                int sum = nums.at(i) + nums.at(lo) + nums.at(hi);
                if(sum == 0) {
                    vector<int> sample = {nums.at(i), nums.at(lo), nums.at(hi)};
                    ans.push_back(sample);
                    while(lo < hi && nums.at(lo) == nums.at(lo+1)) {
                        lo++;
                    }
                    while(lo < hi && nums.at(hi) == nums.at(hi-1)) {
                        hi--;
                    }
                    lo++;
                    hi--;
                } else if(sum > 0) {
                    hi--;
                } else if(sum < 0){
                    lo++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```