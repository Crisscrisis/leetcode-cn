/* leetcode 26
 *
 *
 *
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        int ans = 1;
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i-1) != nums.at(i)) {
                nums.at(j++) = nums.at(i);
                ans++;
            }
        }
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums)
{
    Solution leetcode_26;
    return leetcode_26.removeDuplicates(nums);
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