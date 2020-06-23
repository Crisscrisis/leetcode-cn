/* leetcode 561
 *
 *
 *
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; 2 * i < nums.size(); i++) {
            ans += nums.at(2 * i);
        }
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums)
{
    Solution leetcode_561;
    return leetcode_561.arrayPairSum(nums);
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