/* leetcode 2
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *curr = new ListNode(0);
        head->next = curr;
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = 0;
            if (l1 && l2) {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else if (l2) {
                sum = l2->val + carry;
                l2 = l2->next;
            } else {
                sum = carry;
            }
            if (sum >= 10) {
                sum = sum - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            curr->val = sum;
            if(l1 || l2 || carry) {
                ListNode *tmp = new ListNode(0);
                curr->next = tmp;
                curr = tmp;
            }
        }
        return head->next;
    }
};


/**************************   run solution   **************************/
bool _solution_run(ListNode *head)
{
    return false;
}

#define USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{
    string a = tc.get<string>();
	string b = tc.get<string>();
	ListNode *l1 = StringToListNode(a);
    ListNode *l2 = StringToListNode(b);
    Solution leetcode_2;
	return leetcode_2.addTwoNumbers(l1, l2);
}

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif