/* leetcode 3
 *
 *
 *
 */
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        unordered_set<char> subStr;
        int maxLen = 0;
        int left = 0;
        for(int i = 0; i < s.length(); i++) {
            while (subStr.find(s.at(i)) != subStr.end()) {
                subStr.erase(s.at(left));
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
            subStr.insert(s.at(i));
        }
        return maxLen;
    }
};


/**************************   run solution   **************************/
int _solution_run(string s)
{
    Solution leetcode_3;
    int ans = leetcode_3.lengthOfLongestSubstring(s);
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