/* leetcode 142
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
    ListNode *detectCycle(ListNode *head) {
        if (!hasCycle(head)) {
            return nullptr;
        }
        ListNode* ans;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
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
    string a = tc.get<string>();
	int pos = tc.get<int>();
	ListNode *head = StringIntToCycleListNode(a, pos);
    Solution leetcode_142;
	ListNode *ans = leetcode_142.detectCycle(head);
    if (ans == nullptr) {
        return "no cycle";
    } else {
        return "tail connnects to node index " + convert<string>(pos);
    }
}

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif