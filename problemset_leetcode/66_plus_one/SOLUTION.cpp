/* leetcode 66
 *
 *
 *
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        vector<int> ans(digits.size() + 1);
        ans.at(0) = 1;
        return ans;
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& matrix)
{
    Solution leetcode_66;
    return leetcode_66.plusOne(matrix);
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