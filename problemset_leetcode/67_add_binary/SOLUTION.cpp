/* leetcode 67
 *
 *
 *
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen = b.size();
        string ans{};
        bool carry = false;
        while(!a.empty() && !b.empty()) {
            if (a.back() == '0' && b.back() == '0') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = false;
                }
            }
            if ((a.back() == '0' && b.back() == '1') || (a.back() == '1' && b.back() == '0')) {
                if (carry) {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                }
            }
            if (a.back() == '1' && b.back() == '1') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                }
            }
            a.pop_back();
            b.pop_back();
        }
        while (!a.empty()) {
            if (a.back() == '0') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = false;
                }
            }
            if (a.back() == '1') {
                if (carry) {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                }
            }
            a.pop_back();
        }
        while (!b.empty()) {
            if (b.back() == '0') {
                if (carry) {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                } else {
                    ans.insert(ans.begin(), '0');
                    carry = false;
                }
            }
            if (b.back() == '1') {
                if (carry) {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                } else {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                }
            }
            b.pop_back();
        }
        if (carry) {
            ans.insert(ans.begin(), '1');
        }
        return ans;
    }
};


/**************************   run solution   **************************/
string _solution_run(string a, string b)
{
    Solution leetcode_67;
    return leetcode_67.addBinary(a, b);
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