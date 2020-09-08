/* leetcode 24
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* retNode = new ListNode(0);
        retNode->next = head;
        ListNode* p = retNode;
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr) {
            ListNode* tmp = curr->next->next;
            curr->next->next = curr;
            p->next = curr->next;
            curr->next = tmp;
            p = curr;
            curr = curr->next;
        }
        return retNode->next;
    }
};

#define USE_SOLUTION_CUSTOM
/**************************   run solution   **************************/
ListNode* _solution_run(ListNode* head)
{
    return head;
}

#ifdef USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{
    string a = tc.get<string>();
	ListNode *l1 = StringToListNode(a);
    Solution leetcode_24;
	return leetcode_24.swapPairs(l1);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif