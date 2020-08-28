/* leetcode 146
 *
 *
 *
 */
#include <unordered_map>;
using namespace std;

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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


/**************************   run solution   **************************/
bool _solution_run(DLinkNode *head)
{
    return false;
}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
    vector<string> ans;
    LRUCache* obj = nullptr;
    for(size_t i = 0; i < sf.size(); i++) {
        if(sf[i] == "LRUCache") {
            TestCases stc(sp[i]);
            int capacity = stc.get<int>();
            obj = new LRUCache(capacity);
            ans.push_back("null");
        } else if(sf[i] == "put") {
            TestCases stc(sp[i]);
            int key = stc.get<int>();
            int value = stc.get<int>();
            obj->put(key, value);
            ans.push_back("null");
        } else if(sf[i] == "get") {
            TestCases stc(sp[i]);
            int key = stc.get<int>();
            int ret = obj->get(key);
            ans.push_back(convert<string>(ret));
        }
    }

    delete obj;
	return convert<string>(ans);
}

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif