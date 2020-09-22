/* leetcode 39
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
    void travel(vector<int>& cur, int sum, int begin, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            cur.push_back(candidates.at(i));
            travel(cur, sum + cur.back(), i, target, candidates);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        travel(cur, 0, 0, target, candidates);
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(vector<int>& candidates, int target)
{
    Solution leetcode_39;
    vector<vector<int>> ans = leetcode_39.combinationSum(candidates, target);
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