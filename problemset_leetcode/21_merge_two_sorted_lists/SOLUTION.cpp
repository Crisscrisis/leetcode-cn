/* leetcode 21
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* curr = ret;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
                curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }
        return ret->next;
    }
};

#define USE_SOLUTION_CUSTOM
/**************************   run solution   **************************/
ListNode* _solution_run(ListNode* l1, ListNode* l2)
{
    ListNode* ans = new ListNode(0);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{
	string a = tc.get<string>();
	ListNode *l1 = StringToListNode(a);
    string b = tc.get<string>();
	ListNode *l2 = StringToListNode(b);
    Solution leetcode_21;
	return leetcode_21.mergeTwoLists(l1, l2);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif