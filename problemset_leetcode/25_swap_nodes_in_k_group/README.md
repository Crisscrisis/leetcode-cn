## leetcode25 K 个一组翻转链表

### 思路
```
子问题：反转一个链表(leetcode 206)
对于每k个子链表，做如下操作：
1.确定[1, k] 的节点范围；
2.确定before_head[0],以及next_tail[k+1]节点
3.将[1,k]的链表掐掉尾巴
4.反转[1,k]的链表
5.链接before_head->[k, 1]->next_tail
6.确定下一次的before_head[0]——应该为这次翻转后的尾巴
```

### code
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        while (curr) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // get [1, k] nodes
        // get before_head (0), next_tail(k+1)
        // reverse [1, k]
        // link before_head->[k, 1]->next_tail
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* hairPos = hair;
        ListNode* tail = hair;
        while(tail) {
            for(int i = 0; i < k && tail; i++) {
                tail = tail->next;
            }
            if (!tail) {
                return hair->next;
            }
            ListNode* subFirst = hairPos->next;
            ListNode* nxtSubFirst = tail->next;
            tail->next = nullptr; // cut off
            hairPos->next = reverseList(subFirst);
            subFirst->next = nxtSubFirst;
            hairPos = subFirst;
            tail = hairPos;
        }
        return hair->next;
    }
};
```