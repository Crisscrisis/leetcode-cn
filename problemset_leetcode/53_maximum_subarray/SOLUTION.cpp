/* leetcode 53
 *
 *
 *
 */
#include <string>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp; // dp[i]:the max value of subarray which ends in position of i
        dp.push_back(nums[0]);
        int max = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] < 0) {
                dp.push_back(nums[i]);
            } else {
                dp.push_back(dp[i - 1] + nums[i]);
            }
            if (max < dp[i]) {
                max = dp[i];
            }
        }
        return max;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums)
{
    Solution leetcode_53;
    int ans = leetcode_53.maxSubArray(nums);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{

}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif