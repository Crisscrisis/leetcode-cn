/* offer 38
 *
 *
 *
 */
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm> // std::sort
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> ans;
    // set<string> setAns;
    vector<int> visited;
    void travel(string str, int idx, string org) {
        if (idx == org.size()) {
            // setAns.insert(str);
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < org.size(); i++) {
            if (visited[i] == 0) {
                str.push_back(org.at(i));
                visited[i] = 1;
                travel(str, idx + 1, org);
                str.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<string> permutation(string s) {
        visited.resize(s.size(), 0);
        travel("", 0, s);
        // vector<string> ans(setAns.begin(), setAns.end());
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};


/**************************   run solution   **************************/
vector<string> _solution_run(string s)
{
    Solution offer_38;
    vector<string> ans = offer_38.permutation(s);
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