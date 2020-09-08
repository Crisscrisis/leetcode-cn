## leetcode24 两两交换链表中的节点

### 思路
```
首先，为了方便，创建一个临时节点，指向头节点。假设初始链表为1->2->3->4则有：
p->head(1)->2->3->4->nullptr
其次，curr指针表示当前交换的两个节点的第一个(第一次为head)，方便迭代表示。迭代步骤：
1.每次交换的2个节点的第二个，next指向第1个节点
2.p指向第2个节点
3.第1个节点指向第3个节点
4.p移动到下一对节点的前一个节点(指向下一对节点的第1个)
5.curr移动到下一对节点的第1个
6.开始新一轮循环
```

### code
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* retNode = new ListNode(0);
        retNode->next = head;
        ListNode* p = retNode;
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr) {
            ListNode* tmp = curr->next->next;
            curr->next->next = curr;
            p->next = curr->next;
            curr->next = tmp;
            p = curr;
            curr = curr->next;
        }
        return retNode->next;
    }
};
```