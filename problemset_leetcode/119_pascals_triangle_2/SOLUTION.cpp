/* leetcode 119
 *
 *
 *
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            vector<int> ans;
            return ans;
        }
        vector<int> ans(rowIndex + 1);
        if (rowIndex == 0) {
            ans.at(0) = 1;
            return ans;
        }
        if (rowIndex == 1) {
            ans.at(0) = 1;
            ans.at(1) = 1;
            return ans;
        }
        for (int i = 0; i <= rowIndex; i++) {
            ans[i] = 1;
            for (int j = i; j > 1; j--) {
                ans[j-1] = ans[j-2] + ans[j-1];
            }
        }
        return ans;
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(int rowIndex)
{
    Solution leetcode_119;
    return leetcode_119.getRow(rowIndex);
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