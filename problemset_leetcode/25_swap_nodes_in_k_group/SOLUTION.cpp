/* leetcode 25
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        while (curr) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // get [1, k] nodes
        // get before_head (0), next_tail(k+1)
        // reverse [1, k]
        // link before_head->[k, 1]->next_tail
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* hairPos = hair;
        ListNode* tail = hair;
        while(tail) {
            for(int i = 0; i < k && tail; i++) {
                tail = tail->next;
            }
            if (!tail) {
                return hair->next;
            }
            ListNode* subFirst = hairPos->next;
            ListNode* nxtSubFirst = tail->next;
            tail->next = nullptr; // cut off
            hairPos->next = reverseList(subFirst);
            subFirst->next = nxtSubFirst;
            hairPos = subFirst;
            tail = hairPos;
        }
        return hair->next;
    }
};

#define USE_SOLUTION_CUSTOM
/**************************   run solution   **************************/
ListNode* _solution_run(ListNode* head, int k)
{
    return head;
}

#ifdef USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{
    string a = tc.get<string>();
	ListNode *head = StringToListNode(a);
    int k = tc.get<int>();
    Solution leetcode_25;
	return leetcode_25.reverseKGroup(head, k);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif