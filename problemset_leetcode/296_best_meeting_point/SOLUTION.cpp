/* leetcode 296
 *
 *
 *
 */
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<vector<int>> people;
        vector<int> row, col;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(0).size(); j++) {
                if (grid.at(i).at(j) == 1) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        sort(col.begin(), col.end());
        int dis_x, dis_y, p, q;
        p = 0;
        q = row.size();
        dis_y = row.at(q-- - 1) - row.at(p++);
        while (p < q) {
            dis_y += row.at(q-- - 1) - row.at(p++);
        }
        p = 0;
        q = col.size();
        dis_x = col.at(q-- - 1) - col.at(p++);
        while (p < q) {
            dis_x += col.at(q-- - 1) - col.at(p++);
        }
        return dis_x + dis_y;
    }
};


/**************************   run solution   **************************/
double _solution_run(vector<vector<int>>& grid)
{
    Solution leetcode_296;
    int ans = leetcode_296.minTotalDistance(grid);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{

}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif