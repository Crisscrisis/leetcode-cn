/* leetcode 747
 *
 *
 *
 */
typedef struct
{
    int x, y;
} Point;
bool cmp(Point a, Point b)
{
    return a.y > b.y;
}
class Solution {
public:

    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        vector<Point> numsVec(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numsVec.at(i).x = i;
            numsVec.at(i).y = nums.at(i);
        }
        sort(numsVec.begin(), numsVec.end(), cmp);
        if (numsVec.at(0).y >= numsVec.at(1).y * 2) {
            return numsVec.at(0).x;
        }
        else {
            return -1;
        }
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& matrix)
{
    Solution leetcode747;
    return leetcode747.dominantIndex(matrix);
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