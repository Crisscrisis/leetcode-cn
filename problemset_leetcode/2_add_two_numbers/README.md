## leetcode2 两数相加

### 思路
```
需要想好继续计算的边界条件：l1或l2当前不为nullptr，或者进位标志不为0，三者满足其一即可。
1.当l1和l2均不为nullptr时，当前位的和=l1当前位+l2当前位+进位carry
2.当l1或l2有一个为nullptr时，当前位的和=不为nullptr的当前位+进位carry
3.当l1和l2均为nullptr时，当前位的和=进位carry
且每一位计算之后，需要更新carry进位的值，若当前sum>=10，则carry=1，否则carry=0。
最终需要判断是否往下增加一位，只要当前位计算完之后，满足继续计算的边界条件，就往下增加一位。
```

### code
```c++
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
```