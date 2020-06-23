/* leetcode 344
 *
 *
 *
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin, end;
        if (s.empty()) {
            return;
        }
        begin = 0;
        end = s.size() - 1;
        while(begin < end) {
            swap(s.at(begin++), s.at(end--));
        }
    }
};


/**************************   run solution   **************************/
vector<char> _solution_run(vector<char>& s)
{
    Solution leetcode_344;
    leetcode_344.reverseString(s);
    return s;
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