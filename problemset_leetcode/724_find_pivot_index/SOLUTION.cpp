/* leetcode 724
 *
 *
 *
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 2) {
            return -1;
        }
        int leftIdx = 0;
        int sum = 0;
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum * 2 + nums.at(i) == sum) {
                return i;
            }
            leftSum += nums.at(i);
        }
        return -1;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& matrix)
{
    Solution leetcode_724;
    return leetcode_724.pivotIndex(matrix);
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