/* leetcode 292
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
    bool canWinNim(int n) {
        if (n % 4 == 0) {
            return false;
        }
        return true;
    }
};


/**************************   run solution   **************************/
bool _solution_run(int n)
{
    Solution leetcode_292;
    bool ans = leetcode_292.canWinNim(n);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{

	return leetcode_2.addTwoNumbers(l1, l2);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif