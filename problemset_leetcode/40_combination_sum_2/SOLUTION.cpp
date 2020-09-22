/* leetcode 40
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
    void travel(vector<int>& cur, int sum, int begin, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            if (i > 0 && candidates[i - 1] == candidates[i] && visited[i - 1] == 0) {
                continue;
            }
            if (visited[i] == 0) {
                cur.push_back(candidates.at(i));
                visited[i] = 1;
                travel(cur, sum + cur.back(), i, target, candidates);
                cur.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        visited.resize(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        travel(cur, 0, 0, target, candidates);
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(vector<int>& candidates, int target)
{
    Solution leetcode_40;
    vector<vector<int>> ans = leetcode_40.combinationSum2(candidates, target);
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