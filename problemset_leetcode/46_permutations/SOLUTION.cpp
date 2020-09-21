/* leetcode 46
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
    void travel(vector<int>& cur, int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 0) {
                cur.push_back(nums.at(i));
                visited[i] = 1;
                travel(cur, idx + 1, nums);
                cur.pop_back();
                visited[i] = 0;
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        visited.resize(nums.size(), 0);
        travel(tmp, 0, nums);
        return ans;
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(vector<int>& nums)
{
    Solution leetcode_46;
    vector<vector<int>> ans = leetcode_46.permute(nums);
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