/* leetcode 27
 *
 *
 *
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int ans = nums.size();
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            else {
                ans--;
            }
        }
        while (nums.size() != ans) {
            nums.pop_back();
        }
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums, int val)
{
    Solution leetcode_27;
    return leetcode_27.removeElement(nums, val);
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