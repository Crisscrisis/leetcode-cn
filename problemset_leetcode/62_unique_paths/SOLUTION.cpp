/* leetcode 62
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
    // button to top
#if 0
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i-- ) {
            for (int j = n - 1; j >= 0; j--) {
                if(i == m -1 || j == n - 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
#endif
    // top to button
    int recurse(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        } else if (i < m && j < n) {
            dp[i][j] = recurse(i + 1, j, m, n, dp) + recurse(i, j + 1, m, n, dp);
            return dp[i][j];
        }
        return 1;
    }
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = recurse(1, 1, m, n, dp);
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(int m, int n)
{
    Solution leetcode_62;
    int ans = leetcode_62.uniquePaths(m, n);
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