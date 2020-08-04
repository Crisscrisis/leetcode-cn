/* offer 56_1
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
    vector<int> singleNumbers(vector<int>& nums) {
        int a = 0, b = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res = res ^ nums.at(i);
        }
        int div = 1;
        while ((div & res) == 0) {
            div <<= 1;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] & div) {
                a = a ^ nums[i];
            } else {
                b = b ^ nums[i];
            }
        }
        return {a, b};
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums)
{
    Solution offer_56_1;
    vector<int> ans = offer_56_1.singleNumbers(nums);
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