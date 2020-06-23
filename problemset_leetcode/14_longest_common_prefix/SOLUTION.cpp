/* leetcode 14
 *
 *
 *
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.empty()) {
            return ans;
        }
        sort(strs.begin(),strs.end());
        if (strs.at(0).empty()) {
            return ans;
        }
        int n = strs.size();
        int i = 0;
        for (i = 0; i < strs.at(0).size(); i++) {
            if (strs.at(0).at(i) != strs.at(n-1).at(i)) {
                return strs.at(0).substr(0,i);
            }
        }
        if (i == strs.at(0).size()) {
            return strs.at(0);
        }
        return ans;
    }
};


/**************************   run solution   **************************/
string _solution_run(vector<string>& strs)
{
    Solution leetcode_14;
    return leetcode_14.longestCommonPrefix(strs);
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