/* leetcode 64
 *
 *
 *
 */
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm> // std::sort
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid.at(0).empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid.at(0).size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if (i == 1 || j == 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + grid[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

/**************************   run solution   **************************/
int _solution_run(vector<vector<int>>& grid)
{
    Solution leetcode_64;
    int ans = leetcode_64.minPathSum(grid);
    return ans;
}

// in case of listnode, tree node, we need to use solution_custom
#ifdef USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    string a = tc.get<string>(); // get 1 line from test.txt, if the type of a is string ,use tc.get<string>()
	int b = tc.get<int>(); // get 1 next line from test.txt, if the type of b is int ,use tc.get<int>()
	ListNode *head = StringIntToCycleListNode(a, b);
    Solution leetcode_141;
	return leetcode_141.hasCycle(head);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif