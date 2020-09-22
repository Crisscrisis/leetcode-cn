/* leetcode 78
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
    void dfs(vector<int>& cur, int begin, int len, vector<int>& nums) {
        if (len > nums.size()) {
            return;
        }
        ans.push_back(cur);
        for (int i = begin; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(cur, i + 1, len + 1, nums);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<int> cur;
        dfs(cur, 0, 0, nums);
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(vector<int>& nums)
{
    Solution leetcode_78;
    vector<vector<int>> ans = leetcode_78.subsets(nums);
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