
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int cnt = 0;
        char last = '-';
        for (auto c : s) {
            cnt = (last == c) ? cnt + 1 : 1;
            ans = max(ans, cnt);
            last = c;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << s << endl;
    Solution sln;
    return sln.maxPower(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
