## leetcode142 环形链表2

### 思路
```
假设非环形长度为a，环形长度为b，fast一次走2步，slow一次走1步，第一次相遇时，fast指针走了a+x，slow走了a+y，且有(a+x)=2(a+y)，且x-y=nb,即两者相遇，则fast比slow多走了n圈，故有两者相遇时，fast走了2nb，slow走了nb。需要求a的长度，则此时，slow再走a步即可，如何让slow再走a步就停下？可以发现，入环节点的位置，等于a+nb，则若第一次相遇后，从head开始有一个跟slow相同速度的节点走，则走a步之后，slow刚好也走了a+nb步，则两者在入环点相遇，相遇位置即为所要求的输出
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
```