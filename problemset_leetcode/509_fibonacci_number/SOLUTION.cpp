/* leetcode 509
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
    vector<int> fib_vec = vector<int> (31,0);
    int fib(int N) {
        if(N == 0) {
            fib_vec[0] = 0;
            return fib_vec[N];
        }
        if(N == 1) {
            fib_vec[1] = 1;
            return fib_vec[N];
        }
        if(fib_vec[N] != 0) {
            return fib_vec[N];
        } else {
            fib_vec[N] = fib(N -1) + fib(N - 2);
        }
        return fib_vec[N];
    }
};


/**************************   run solution   **************************/
int _solution_run(int n)
{
    Solution leetcode_509;
    int ans = leetcode_509.fib(n);
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