/* leetcode 151
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
        stack<string> words;
        string currWord;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == ' ') {
                if (!currWord.empty()) {
                    words.push(currWord);
                    currWord = {};
                }
            } else {
                currWord.push_back(s.at(i));
            }
        }
        if (!currWord.empty()) {
            words.push(currWord);
        }
        string ans;
        if (words.empty()) {
            return ans;
        }
        int wordsNum = words.size();
        for (int i = 0; i < wordsNum - 1; i++) {
            ans.append(words.top());
            ans.append(" ");
            words.pop();
        }
        ans.append(words.top());
        return ans;
    }
};


/**************************   run solution   **************************/
string _solution_run(string s)
{
    Solution leetcode_151;
    return leetcode_151.reverseWords(s);
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