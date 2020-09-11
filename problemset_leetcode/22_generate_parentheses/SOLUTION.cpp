/* leetcode 22
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
    void generate(int left, int right, int max, vector<string>& str, string tmpstr) {
        // terminator
        if (left < right || left > max || right > max) {
            return;
        }
        if ( left == max && right == max ) {
            str.push_back(tmpstr);
            return;
        }

        // process current logic
        string s1 = tmpstr + "(";
        string s2 = tmpstr + ")";

        // drill down
        generate(left + 1, right, max, str, s1);
        generate(left, right + 1, max, str, s2);

        // restore current status
    }

    vector<string> generateParenthesis(int n) {
        vector<string> str;
        generate(0, 0, n, str, "");
        return str;
    }
};


/**************************   run solution   **************************/
vector<string> _solution_run(int n)
{
    Solution leetcode_22;
    return leetcode_22.generateParenthesis(n);
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