/* leetcode 84
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
    int largestRectangleArea(vector<int>& heights) {
        
        // insert Sentinel to 2 sides of input vector
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        
        deque<int> stk;
        int maxArea = 0; 
        for(int i = 0; i < heights.size(); i++) {
            // stack top is strictly smaller than current
            while(!stk.empty() && heights[stk.back()] > heights[i]) {
                int cur = stk.back();
                stk.pop_back();
                int left = stk.back();
                int right = i - 1;
                // max area of the current height in from position [0,cur]
                int tmpArea = (right - left) * heights[cur];
                maxArea = max(maxArea, tmpArea);
            }
            // stack top is euqal or larger to current
            stk.emplace_back(i);
        }
        return maxArea;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& heights)
{
    Solution leetcode_84;
    int ans = leetcode_84.largestRectangleArea(heights);
    return ans;
}

// in case of listnode, tree node, we need to use solution_custom
#ifdef USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    string a = tc.get<string>(); // get 1 line from test.txt, if the type of a is string ,use tc.get<string>()
	int b = tc.get<int>(); // get 1 next line from test.txt, if the type of b is int ,use tc.get<int>()
	ListNode *head = StringIntToCycleListNode(a, b);
    Solution leetcode_141;
	return leetcode_141.hasCycle(head);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif