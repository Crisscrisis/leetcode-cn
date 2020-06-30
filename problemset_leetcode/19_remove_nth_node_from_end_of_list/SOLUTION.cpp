/* leetcode 19
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        ListNode* tmp = head;
        int cnt = 0;
        while(tmp) {
            cnt++;
            tmp = tmp->next;
        }
        int move = cnt - n;
        tmp = head;
        if (move == 0) {
            head = tmp->next;
            delete tmp;
            return head;
        }
        for (int i = 0; i < move - 1; i++) {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};


/**************************   run solution   **************************/
bool _solution_run(ListNode *head)
{
    return false;
}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    string list = tc.get<string>();
    int index = tc.get<int>();
    ListNode *head = StringToListNode(list);
    Solution leetcode_19;
    ListNode *ans = leetcode_19.removeNthFromEnd(head, index);
    if (ans == nullptr) {
        return "null";
    } else {
        return ListNodeToString(ans);
    }
}

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif