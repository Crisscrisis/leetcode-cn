/* leetcode 498
 *
 *
 *
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            vector<int> ans;
            return ans;
        }
        int col = matrix.at(0).size();
        vector<int> ans;
        int sums = row + col - 2;
        int cnt = 0;
        for (int sum = 0; sum <= sums; sum++) {
            vector<int> tmp;
            for (int i = 0; i < row; i++) {
                int j = sum - i;
                if (j < col && j >= 0) {
                    tmp.push_back(matrix[i][j]);
                }
            }
            cnt++;
            if (cnt % 2 == 1) {
                reverse(tmp.begin(), tmp.end());
            }
            for (int n = 0; n < tmp.size(); n++) {
                ans.push_back(tmp.at(n));
            }
        }
        return ans;
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<vector<int>>& matrix)
{
    Solution leetcode_498;
    return leetcode_498.findDiagonalOrder(matrix);
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