/* leetcode 118
 *
 *
 *
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if (numRows == 0) {
            return ans;
        }
        ans.at(0).push_back(1);
        for (int i = 1; i < numRows; i++) {
            ans.at(i).push_back(1);
            for (int j = 1; j < i; j++) {
                ans.at(i).push_back(ans.at(i-1).at(j - 1) + ans.at(i-1).at(j));
            }
            ans.at(i).push_back(1);
        }
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(int numRows)
{
    Solution leetcode_118;
    return leetcode_118.generate(numRows);
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