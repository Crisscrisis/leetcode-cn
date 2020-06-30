/* leetcode 707
 *
 *
 *
 */
class MyLinkedList {
struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x):val(x), next(nullptr){}
    };
    int m_size;
    ListNode* m_head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        m_head = nullptr;
        m_size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index > m_size || m_size == 0) {
            return -1;
        }
        ListNode* tmp = m_head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        if(tmp) {
            return tmp->val;
        } else {
            return -1;
        }

    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = m_head;
        m_head = newHead;
        m_size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (m_size == 0) {
            addAtHead(val);
            return;
        }
        ListNode* tmp = m_head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        if (tmp) {
            tmp->next = new ListNode(val);
            m_size++;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > m_size) {
            return;
        } else if (index == m_size) {
            addAtTail(val);
            return;
        } else if (index <= 0) {
            addAtHead(val);
            return;
        } else {
            ListNode* tmp = m_head;
            ListNode* newNode = new ListNode(val);
            for (int i = 0; i < index - 1; i++) { // find the element which is ahead of the insert position
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
            m_size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index > m_size || m_size == 0) {
            return;
        }
        ListNode* tmp = m_head;
        if (index == 0) {
            m_head = m_head->next;
            m_size--;
            delete tmp;
            return;
        }
        for (int i = 0; i < index - 1; i++) { // find the element which is ahead of the delete position
            tmp = tmp->next;
        }
        if (!tmp) {
            return;
        }
        if (tmp->next) {
            ListNode* del = tmp->next;
            tmp->next = del->next;
            delete del;
            m_size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums)
{
    return {};
}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

    MyLinkedList *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
        if (sf[i] == "MyLinkedList")
        {
            obj = new MyLinkedList();
            ans.push_back("null");
        } else if (sf[i] == "addAtHead")
        {
            TestCases stc(sp[i]);
            int val = stc.get<int>();
            obj->addAtHead(val);
            ans.push_back("null");
        } else if (sf[i] == "addAtTail")
        {
            TestCases stc(sp[i]);
            int val = stc.get<int>();
            obj->addAtTail(val);
            ans.push_back("null");
        } else if (sf[i] == "addAtIndex")
        {
            TestCases stc(sp[i]);
            int index = stc.get<int>();
            int val = stc.get<int>();
            obj->addAtIndex(index, val);
            ans.push_back("null");
        } else if (sf[i] == "get")
        {
            TestCases stc(sp[i]);
            int index = stc.get<int>();
            int rVal = obj->get(index);
            ans.push_back(convert<string>(rVal));
        } else if (sf[i] == "deleteAtIndex")
        {
            TestCases stc(sp[i]);
            int index = stc.get<int>();
            obj->deleteAtIndex(index);
            ans.push_back("null");
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