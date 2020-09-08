/* leetcode 1
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

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

/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums, int target)
{
    Solution leetcode_1;
    vector<int> ans = leetcode_1.twoSum(nums, target);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
int _solution_custom(TestCases &tc)
{
	return 0;
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif