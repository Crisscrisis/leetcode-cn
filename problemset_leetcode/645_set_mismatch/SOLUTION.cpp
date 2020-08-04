/* leetcode 645
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
    vector<int> findErrorNums(vector<int>& nums) {
        int dupMiss = 0; // dup ^ miss
        vector<int> wholeNums;
        int a = 0, b = 0;
        for (int num: nums) {
            dupMiss = dupMiss ^ num;
            wholeNums.push_back(num);
        }
        for (int i = 0; i < nums.size(); i ++) {
            dupMiss = dupMiss ^ (i + 1);
            wholeNums.push_back(i + 1);
        }
        int div = 1;
        while((div & dupMiss) == 0) {
            div = div << 1;
        }

        for (int num: wholeNums) {
            if ((num & div) == 0) {
                a = a ^ num;
            } else {
                b = b ^ num;
            }
        }
        for (int num: nums) {
            if(num == a) {
                return {a, b};
            }
        }
        return {b, a};
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums)
{
    Solution leetcode_645;
    vector<int> ans = leetcode_645.findErrorNums(nums);
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