/* leetcode 300
 *
 *
 *
 */
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int len = nums.size();
        vector<int> dp(len, 0);
        int maxVal = 1;
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (maxVal < dp[i]) {
                    maxVal = dp[i];
                }
            }
        }
        return maxVal;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums)
{
    Solution leetcode_300;
    int ans = leetcode_300.lengthOfLIS(nums);
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