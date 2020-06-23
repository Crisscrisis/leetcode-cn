/* leetcode 557
 *
 *
 *
 */
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            string ans;
            return ans;
        }
        int begin = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == ' ') {
                while (begin < end){
                    char tmp = s.at(begin);
                    s.at(begin) = s.at(end);
                    s.at(end) = tmp;
                    begin++;
                    end--;
                }
                begin = i + 1;
            } else {
                end = i;
            }
        }
        if (s.at(s.size() - 1) != ' '){
            while (begin < end){
                    char tmp = s.at(begin);
                    s.at(begin) = s.at(end);
                    s.at(end) = tmp;
                    begin++;
                    end--;
                }
        }
        return s;
    }
};


/**************************   run solution   **************************/
string _solution_run(string s)
{
    Solution leetcode_557;
    return leetcode_557.reverseWords(s);
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