/* leetcode 260
 *
 *
 *
 */
#include <string>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int dif = 0, a = 0, b = 0;
        for(int num: nums) {
            dif = dif ^ num;
        }
        int div = 1;
        while ((div & dif) == 0) {
            div = div << 1;
        }
        for(int num: nums) {
            if((num & div) == 0) {
                a = a ^ num;
            } else {
                b = b ^ num;
            }
        }
        return {a, b};

    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums)
{
    Solution leetcode_260;
    vector<int> ans = leetcode_260.singleNumber(nums);
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