/* leetcode 54
 *
 *
 *
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix.at(0).size() - 1;
        while(true) {
            // right
            for (int k = left; k <= right; k++) {
                ans.push_back(matrix.at(up).at(k));
            }
            if (++up > down) {
                break;
            }

            // down
            for (int k = up; k <= down; k++) {
                ans.push_back(matrix.at(k).at(right));
            }
            if (--right < left) {
                break;
            }

            // left
            for (int k = right; k >= left; k--) {
                ans.push_back(matrix.at(down).at(k));
            }
            if (--down < up) {
                break;
            }

            // up
            for (int k = down; k >= up; k--) {
                ans.push_back(matrix.at(k).at(left));
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<vector<int>>& matrix)
{
    Solution leetcode_54;
    return leetcode_54.spiralOrder(matrix);
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