/* template number
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
    <T1> foo(<T2>& param) {
        <T1> ans;
        //process
        return ans;
    }
};


/**************************   run solution   **************************/
<T1> _solution_run(<T2>>& param)
{
    Solution template;
    <T1> ans = template.foo(param);
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