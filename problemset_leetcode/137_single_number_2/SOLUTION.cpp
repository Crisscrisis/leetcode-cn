/* leetcode 137
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
#if 0
    // hash map
    int singleNumber(vector<int>& nums) {
        map<int, int> maps;
        for (auto num: nums){
            if(maps.find(num) == maps.end()) {
                maps.insert({num, 1});
            } else {
                maps.at(num) += 1;
            }
        }
        for (auto num:nums) {
            if(maps.at(num) == 1) {
                return num;
            }
        }
        return 0;
    }

    // bit manipulation
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (auto num: nums) {
                if ((num >> i) & 1 == 1) {
                    cnt++;
                }
            }
            if (cnt % 3 != 0) {
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
#endif
    // bit manipulation 2
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        int ans = 0;
        for (auto num: nums) {
            for (int i = 0; i < 32; i++) {
                bits[i] += (num >> i) & 1;
            }
        }
        for (int i = 0; i < 32; i++) {
            ans = ans | ((bits[i] % 3) << i);
        }
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums)
{
    Solution leetcode_137;
    int ans = leetcode_137.singleNumber(nums);
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