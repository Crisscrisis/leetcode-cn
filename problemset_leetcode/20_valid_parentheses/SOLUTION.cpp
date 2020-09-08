/* leetcode 20
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(char s, char pa) {
        if (pa == '(') {
            if (s == ')') {
                return true;
            } else {
                return false;
            }
        } else if (pa == '{') {
            if (s == '}') {
                return true;
            } else {
                return false;
            }
        } else if (pa == '[') {
            if (s == ']') {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    bool isValid(string s) {
        deque<char> parentheses(1);
        if (s.empty()) {
            return true;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                parentheses.push_back(s[i]);
            } else {
                bool ans = isMatch(s[i], parentheses.back());
                if (ans) {
                    parentheses.pop_back();
                } else {
                    return false;
                }
            }
        }
        if(parentheses.size() == 1) {
            return true;
        }
        return false;
    }
};

/**************************   run solution   **************************/
bool _solution_run(string s)
{
    Solution leetcode_20;
    bool ans = leetcode_20.isValid(s);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
bool _solution_custom(TestCases &tc)
{

	return false;
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif