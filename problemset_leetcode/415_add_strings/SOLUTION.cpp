/* leetcode 415
 *
 *
 *
 */
#include <string>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1Size = num1.size();
        int num2Size = num2.size();
        int i = num1Size - 1, j = num2Size - 1, tmp = 0, carry = 0;
        string ans;
        while(i >= 0 && j >= 0) {
            tmp = num1[i--] - '0' + num2[j--] - '0' + carry;
            if (tmp >= 10) {
                tmp = tmp - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans += (tmp + '0');
        }
        if (i >= 0) {
            while(i >= 0) {
                tmp = num1[i--] - '0' + carry;
                if(tmp >= 10) {
                    tmp = tmp - 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                ans += (tmp + '0');
            }
        }
        if (j >= 0) {
            while (j >= 0) {
                tmp = num2[j--] - '0' + carry;
                if(tmp >= 10) {
                    tmp = tmp - 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                ans += (tmp + '0');
            }
        }
        if(carry == 1) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


/**************************   run solution   **************************/
string _solution_run(string num1, string num2)
{
    Solution leetcode_415;
    string ans = leetcode_415.addStrings(num1, num2);
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