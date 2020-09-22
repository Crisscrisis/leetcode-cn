/* offer 24
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
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *cur = nullptr;
        while(head != nullptr) {
            ListNode *tmp = head->next;
            head->next = cur;
            cur = head;
            head = tmp;
        }
        return cur;
    }
};

#define USE_SOLUTION_CUSTOM
/**************************   run solution   **************************/
int _solution_run(string s)
{
    return 0;
}

#ifdef USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{
    string a = tc.get<string>();
	ListNode *head = StringToListNode(a);
    Solution offer_24;
	return offer_24.reverseList(head);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif