/* leetcode 121
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
using namespace std;

class Solution {
public:
    // dp
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() < 2) {
            return 0;
        }
        int minPrice = prices[0];
        vector<int> dp(prices.size(), 0);
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp.back();
    }
    // monotone stack
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> st;
        prices.emplace_back(-1);
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && st.back() > prices[i]) {
                ans = max(ans, st.back() - st.front());
                st.pop_back();
            }
            st.emplace_back(prices[i]);
        }
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& prices)
{
    Solution leetcode_121;
    return leetcode_121.maxProfit(prices);
}

#ifdef USE_SOLUTION_CUSTOM
vector<vector<int>> _solution_custom(TestCases &tc)
{
    return {};
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif