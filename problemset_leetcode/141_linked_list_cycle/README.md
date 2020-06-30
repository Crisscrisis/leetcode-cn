## leetcode141 环形链表

### 思路
```
快慢指针法，注意：
1.fast和slow的初始化都为head
2.跳出while循环的条件是判读fast和fast->next是否为空，不能判断slow，因为slow慢，判断无意义
3.需考虑head为空的特殊情况
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
};
```