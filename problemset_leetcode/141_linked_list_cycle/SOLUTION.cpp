/* leetcode 141
 *
 *
 *
 */
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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};


/**************************   run solution   **************************/
bool _solution_run(ListNode *head)
{
    return false;
}

#define USE_SOLUTION_CUSTOM
bool _solution_custom(TestCases &tc)
{
    string a = tc.get<string>();
	int b = tc.get<int>();
	ListNode *head = StringIntToCycleListNode(a, b);
    Solution leetcode_141;
	return leetcode_141.hasCycle(head);
}

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif