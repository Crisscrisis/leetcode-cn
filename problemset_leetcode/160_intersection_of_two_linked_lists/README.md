## leetcode160 相交链表

### 思路
```
构建哈希表，将A的所有点存入，然后遍历B，在其中找相同的指针，如果能找到则返回找到的指针，否则返回nullptr
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
```