/* offer 62
 *
 *
 *
 */
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
// f(1, m) = 0
// f(2, m) = (f(1, m) + m)%2
// f(n, m) = (f(n-1, m) + m)%n
class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        for (int i = 2; i <= n; i++) {
            pos = (pos + m) % i;
        }
        return pos;
    }
};


/**************************   run solution   **************************/
int _solution_run(int n, int m)
{
    Solution offer_62;
    int ans = offer_62.lastRemaining(n, m);
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