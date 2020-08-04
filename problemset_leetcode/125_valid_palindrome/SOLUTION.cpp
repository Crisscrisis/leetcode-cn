/* leetcode 125
 *
 *
 *
 */
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) {
            return true;
        }
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            if (!isalnum(s[l])) {
                r++;
                continue;
            } else if (!isalnum(s[r])) {
                l--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
        }
        return true;
    }
};


/**************************   run solution   **************************/
int _solution_run(string s)
{
    Solution leetcode_125;
    int ans = leetcode_125.isPalindrome(s);
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