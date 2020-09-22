/* leetcode 90
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
        // 同层使用过的元素，同层其他分支不再使用，使用begin标识
        for (int i = begin; i < nums.size(); i++) {
            // 排除重复元素，使用visited
            if (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == 0) {
                continue;
            }
            if (visited[i] == 0) {
                cur.push_back(nums[i]);
                visited[i] = 1;
                dfs(cur, i + 1, len + 1, nums);
                cur.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<int> cur;
        visited.resize(nums.size(), 0);
        // 使用visited之前，需要先排序
        sort(nums.begin(), nums.end());
        dfs(cur, 0, 0, nums);
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(vector<int>& nums)
{
    Solution leetcode_90;
    vector<vector<int>> ans = leetcode_90.subsetsWithDup(nums);
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