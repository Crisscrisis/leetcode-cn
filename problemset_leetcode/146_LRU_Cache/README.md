## leetcode146 LRU缓存机制

### 思路
```
使用哈希链表，先用hash map，根据key关联节点，对于每个节点，有key和value，节点用一个链表来管理，链表的表头放最近使用的元素，表尾放最早使用的元素。
需要构造几个api方便操作：1.删除表中的一个节点；2.将一个节点添加到表头(因为本场景中，如果要添加节点到链表中，必定其在最新使用的位置，即为表头)；
3.将一个节点移动到表头（更新元素时会用到）；4.删除表尾的节点（超出capacity时会用到）
```

### code
```c++
struct DLinkNode {
    int key, value;
    DLinkNode* prev;
    DLinkNode* next;
    DLinkNode():key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkNode*> cache;
    DLinkNode* head; // latest use
    DLinkNode* tail; // earliest use
    int _size;
    int _capacity;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    void addToHead(DLinkNode* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void removeNode(DLinkNode* node) { // node must be in the dlinklist
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void moveToHead(DLinkNode* node) { // node must be in the dlinklist
        removeNode(node);
        addToHead(node);
    }

    DLinkNode* removeTail() {
        DLinkNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    int get(int key) {
        if(cache.count(key) == 0) {
            return -1;
        }
        DLinkNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if(cache.count(key)) {
            DLinkNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (_size < _capacity) {
                DLinkNode* node = new DLinkNode(key, value);
                addToHead(node);
                moveToHead(node);
                cache.insert(make_pair(key, node));
                _size++;
            } else {
                int oldKey = tail->prev->key;
                removeNode(tail->prev);
                DLinkNode* node = new DLinkNode(key, value);
                addToHead(node);
                moveToHead(node);
                cache.insert(make_pair(key, node));
                cache.erase(oldKey);
            }
        }
    }
};
```