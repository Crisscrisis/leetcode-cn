/* leetcode 160
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return nullptr;
        }
        ListNode* iterA = headA;
        ListNode* iterB = headB;
        unordered_set<ListNode*> set;
        while(iterA) {
            set.insert(iterA);
            iterA = iterA->next;
        }
        while(iterB) {
            if(set.find(iterB) != set.end()) {
                return iterB;
            }
            iterB = iterB->next;
        }
        return nullptr;
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
    int interSecVal = tc.get<int>();
    string l1 = tc.get<string>();
    string l2 = tc.get<string>();
    int k1 = tc.get<int>();
    int k2 = tc.get<int>();
    ListNode *pA = nullptr;
    ListNode *pB = nullptr;
    StringIntToIntersectionNode(&pA, &pB, l1, l2, k1, k2);
    Solution leetcode_160;
    ListNode *ans = leetcode_160.getIntersectionNode(pA, pB);
    if (ans == nullptr) {
        return "null";
    } else {
        return "Reference of the node with value = " + convert<string>(ans->val);
    }
}

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif