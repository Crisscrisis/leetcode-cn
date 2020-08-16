/* leetcode 416
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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum >>= 1;
        int n = nums.size();
        vector<vector<bool>>dp(n+1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};


/**************************   run solution   **************************/
bool _solution_run(vector<int>& nums)
{
    Solution leetcode_416;
    bool ans = leetcode_416.canPartition(nums);
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