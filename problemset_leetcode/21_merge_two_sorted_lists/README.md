## leetcode21 合并两个有序链表

### 思路
```
设置一个哨兵节点，他的下一个指向的是返回的链表头。每次只需要比较，将l1和l2中较小的那个链到下一个即可。
l1或l2遍历完之后，将剩余的接到最后即可。
```

### code
```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* curr = ret;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
                curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }
        return ret->next;
    }
};
```