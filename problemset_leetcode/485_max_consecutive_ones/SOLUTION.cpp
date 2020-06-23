/* leetcode 485
 *
 *
 *
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int sum = 0;
        int maxSum = sum;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == 1) {
                sum++;
            } else {
                if (maxSum < sum) {
                    maxSum = sum;
                }
                sum = 0;
            }
        }
        if (maxSum < sum) {
            maxSum = sum;
        }
        return maxSum;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& nums)
{
    Solution leetcode_485;
    return leetcode_485.findMaxConsecutiveOnes(nums);
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