/* leetcode 209
 *
 *
 *
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int tmpLen = 0;
        int minLen = 0;
        int sum = 0;
        int arrayStart = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
            tmpLen++;
            if (sum >= s && minLen == 0) {
                minLen = tmpLen;
            }
            while ((sum - nums.at(arrayStart)) >= s) {
                sum = sum - nums.at(arrayStart);
                arrayStart++;
                tmpLen--;
                if (minLen > tmpLen || minLen == 0) {
                    minLen = tmpLen;
                }
            }
        }
        return minLen;
    }
};


/**************************   run solution   **************************/
int _solution_run(int s, vector<int>& nums)
{
    Solution leetcode_209;
    return leetcode_209.minSubArrayLen(s, nums);
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