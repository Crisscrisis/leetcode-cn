/* leetcode 283
 *
 *
 *
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int j = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums.at(i) != 0) {
                nums.at(j++) = nums.at(i);
                cnt++;
            }
        }
        for (int i = cnt; i < nums.size(); i++) {
            nums.at(i) = 0;
        }
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums)
{
    Solution leetcode_283;
    leetcode_283.moveZeroes(nums);
    return nums;
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