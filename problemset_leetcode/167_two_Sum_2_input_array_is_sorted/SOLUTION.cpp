/* leetcode 167
 *
 *
 *
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        if (numbers.empty() || numbers.size() == 0) {
            return ans;
        }
        int begin = 0;
        int end = numbers.size() - 1;
        int sum = numbers.at(begin) + numbers.at(end);
        while( sum != target && begin < end) {
            if (sum < target) {
                begin++;
                sum = numbers.at(begin) + numbers.at(end);
            } else {
                end--;
                sum = numbers.at(begin) + numbers.at(end);
            }
        }
        if (sum == target) {
            ans.push_back(++begin);
            ans.push_back(++end);
            return ans;
        } else {
            return ans;
        }
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& numbers, int target)
{
    Solution leetcode_167;
    return leetcode_167.twoSum(numbers, target);
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