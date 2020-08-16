/* leetcode 5
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
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        int len = s.length();
        int dp[500][500]; // 1000 is good for leetcode debugger, but will cause stack overflow fault in visual studio debug
        int front = 0;
        int tail = 0;
        int maxLen = 0;
        int i, j;
        for (i = 0; i < len; i++) {
            dp[i][i] = 1;
        }
        for (j = 1; j < len; j++) {
            for (i = 0; i < j; i++) {
                if(s.at(i) != s.at(j)) {
                    dp[i][j] = 0;
                } else {
                    if (j - i < 2) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if (dp[i][j] == 1 && ((j - i + 1) > maxLen)) {
                        maxLen = j - i + 1;
                        front = i;
                    }
                }
            }
        }
        if(maxLen == 0) {
            return s.substr(0, 1);
        }
        return s.substr(front, maxLen);
    }
};


/**************************   run solution   **************************/
string _solution_run(string s)
{
    Solution leetcode_5;
    string ans = leetcode_5.longestPalindrome(s);
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