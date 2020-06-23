/* leetcode 28
 *
 *
 *
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty() || haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            int k = i;
            int j = 0;
            while ( k < haystack.size() && j < needle.size() && haystack.at(k) == needle.at(j) ) {
                k++;
                j++;
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};


/**************************   run solution   **************************/
int _solution_run(string haystack, string needle)
{
    Solution leetcode_28;
    return leetcode_28.strStr(haystack, needle);
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