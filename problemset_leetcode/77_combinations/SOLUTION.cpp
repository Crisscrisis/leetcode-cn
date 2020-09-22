/* leetcode 77
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
    vector<vector<int>> ans;
    vector<int> visited;
    void dfs(vector<int>& cur, int n, int k, int begin, int len) {
        if (len == k) {
            ans.push_back(cur);
            return;
        }
        if (len > k) {
            return;
        }
        for (int i = begin; i <= n; i++) {
            cur.push_back(i);
            dfs(cur, n, k, i + 1, len + 1);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        if (n == 0) {
            return ans;
        }
        vector<int> cur;
        dfs(cur, n, k, 1, 0);
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(int n, int k)
{
    Solution leetcode_77;
    vector<vector<int>> ans = leetcode_77.combine(n, k);
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