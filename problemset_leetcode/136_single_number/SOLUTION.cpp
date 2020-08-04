/* leetcode 136
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
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto i:nums) {
            ans = ans ^ i;
        }
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums)
{
    Solution leetcode_136;
    int ans = leetcode_136.singleNumber(nums);
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