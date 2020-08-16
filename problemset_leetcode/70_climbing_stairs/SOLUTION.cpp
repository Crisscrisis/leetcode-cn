/* leetcode 70
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
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int dp[1000];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


/**************************   run solution   **************************/
int _solution_run(int n)
{
    Solution leetcode_70;
    int ans = leetcode_70.climbStairs(n);
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