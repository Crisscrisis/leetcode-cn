## leetcode24 反转链表

### 思路
```
head表示当前的头，设置一个cur节点，用于存储当前指向的节点，cur->next = head。下次反转的时候，head往下走，而head->next = cur，cur也往下走，依次类推。
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
```