## leetcode19 删除链表的倒数第N个节点

### 思路
```
首先遍历一遍，算出链表长度，然后算出删除倒数第N个节点，实际是要删的位置的前导位置个，然后进行删除操作
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
```