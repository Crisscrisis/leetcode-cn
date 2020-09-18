#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm> // std::sort
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_set>
#include<unordered_map>


#ifdef BASIC_DATA_STRUCTURE
/********** sequential container **********/
    // str = "abcdefg"
    //        |      |
    //       begin   end
    // foo(str.begin(), str.end()); [pos of begin, pos of end)
    // foo(pos, len); [pos, pos + len)
    string strExample = "1234"; // index from 0 to 3
    string strExample2(5,'x');
    int iresult = stoi(strExample);
    string sresult = to_string(iresult);
    strExample = "12.34";
    float fresult = stof(strExample);
    sresult = to_string(fresult);
    strExample = "abcdefg";
    string insertStr = "aa";
    strExample.insert(4, insertStr);
    bool isEmpty = strExample.empty(); // if strExample not empty, return false
    char cresult = strExample.at(0); // cresult = 'a'
    int len = strExample.size(); // len = 9
    len = strExample.length(); // len = 9
    cresult = strExample.front(); // cresult = 'a'
    cresult = strExample.at(len - 1); // cresult = 'g'
    cresult = strExample.back(); // cresult = 'g'
    int pos = strExample.find("aa"); // pos = 4, the index of the first element in "aa" in strExample
    int nopos = strExample.find("x"); // not find, pos = -1
    strExample.erase(strExample.begin() + 4, strExample.begin() + 6); // delete index [4, 6)
    strExample.push_back('x'); // must be char
    strExample.erase(strExample.end() - 1); // delete last
    strExample.append("xy"); // abcdefgxy
    strExample.pop_back(); // abcdefgx
    strExample.erase(0,2); // erase from index range [0, 2) cdefgx 0:pos, 2: length
    strExample.insert(0, "ab"); // abcdefgx
    strExample.swap(insertStr); // swap insertStr and strExample
    strExample.swap(insertStr);
    strExample.replace(0,1,"xyz"); // xyzbcdefgx 0:pos, 1: length
    sresult = strExample.substr(1,3); // index range [1, 3] sresult yzb 0:pos, 3:length
    pos = strExample.find("e"); // pos = 6 in xyzbcdefgx
    sresult = strExample.substr(pos); // index range [pos, len)
    pos = strExample.find_first_of('x'); // return first index of 'x'
    pos = strExample.find_last_of('x');
    pos = strExample.find_first_not_of('x');
    pos = strExample.find_last_not_of('x');
    string strA = "abcd";
    string strB = "abce";
    iresult = strA.compare(strB); // abcd < abce, return -1
    iresult = strA.compare(1,3,strB); // bcd > abce, return 1 1:pos, 3:length

    // vector
    // erase(iterA, iterB) delete [A, B)
    // erase(iter) dllete iter
    // insert(iter, iter, iter)
    vector<int> vecExample = {0, 1, 2, 3, 4, 5, 6};
    vector<int> vecExample2(5,11);
    iresult = vecExample.size();
    isEmpty = vecExample.empty();
    iresult = vecExample.front();
    iresult = vecExample.back();
    int* pVec = vecExample.data();
    vector<int> insetrVec = {11, 22, 33};
    vector<int>::iterator it = vecExample.begin(); // it->0
    vecExample.insert(it + 1, insetrVec.begin(), insetrVec.begin() + 3); // vecExample:[0,11,22,33,1,2,3,4,5,6]
    it = vecExample.begin() + 1; // it->11
    vecExample.erase(it); //[0,22,33,1,2,3,4,5,6]
    it = vecExample.begin() + 1; // it->22
    vecExample.erase(it, it+2); //[0,1,2,3,4,5,6]
    vecExample.push_back(7);
    vecExample.pop_back();

    // list
    list<vector<int>> listExample;
    auto posList = listExample.begin();
    vector<int> tmp(10);
    listExample.insert(posList, tmp);
    posList = listExample.begin();
    advance(posList, 1);
    tmp.resize(5);
    listExample.insert(posList, tmp);
    posList = listExample.begin();
    tmp.resize(3);
    advance(posList, 2);
    listExample.insert(posList, tmp);
    vector<vector<int>> vecRet(listExample.begin(), listExample.end());

    // queue
    queue<int> queExample;
    queExample.push(0);
    queExample.push(1);
    queExample.push(2);
    iresult = queExample.front();
    iresult = queExample.back();
    iresult = queExample.size();
    while(!queExample.empty()) {
        queExample.pop();
    }

    // stack
    stack<int> stkExample;
    stkExample.push(0);
    stkExample.push(1);
    stkExample.push(2);
    iresult = stkExample.top();
    iresult = stkExample.size();
    while(!stkExample.empty()) {
        stkExample.pop();
    }

    // deque
    deque<int> dequeExample(5,1);
    dequeExample.push_back(2);
    dequeExample.push_front(3);
    iresult = dequeExample.front();
    iresult = dequeExample.back();
    iresult = dequeExample.size();
    iresult = dequeExample[3];
    iresult = dequeExample.at(5);
    dequeExample.pop_back();
    dequeExample.pop_front();
    isEmpty = dequeExample.empty();
    dequeExample.resize(15);
    deque<int>::iterator itDeque = dequeExample.begin();
    dequeExample.insert(itDeque, 8);
    dequeExample.emplace_front(7);
    dequeExample.emplace_back(9);
    itDeque = dequeExample.begin();
    dequeExample.emplace(itDeque + 3, 10);
    dequeExample.erase(dequeExample.begin());
    dequeExample.erase(dequeExample.begin(), dequeExample.begin() + 3);

/********** ordered associative container **********/
    // pair
    pair<string, int> pairExample("David", 3);
    sresult = pairExample.first;
    iresult = pairExample.second;
    pairExample.first = "bill";
    pairExample.second = 10;

    // map map<key, value> sorted by order of key, ascending order
    pair<string, int> pair1("David", 1);
    pair<string, int> pair2("Corina", 2);
    pair<string, int> pair3("Carla", 3);
    pair<string, int> pair4("Rous", 4);
    map<string, int> mapExample;
    mapExample.emplace(pair1);
    mapExample.emplace("Test", 6);
    mapExample.emplace(pair2);
    mapExample.emplace(pair3);
    mapExample.emplace(pair4);
    mapExample.emplace("Test", 8); // key "Test" already inserted, can't insert another pair with key "Test"
    mapExample["Test"] = 10; // modify the value of key "Test"
    if(mapExample.find("David") != mapExample.end()) { //found
        iresult = mapExample.count("David");
        iresult = mapExample["David"];
        mapExample.erase("David");
    }
    iresult = mapExample.count("TT");

    // multimap <key, value>
    multimap<string, int> multimapExample;
    multimap<string, int>::iterator itMultimap;
    multimapExample.emplace(pair1);
    multimapExample.emplace("Test", 6);
    multimapExample.emplace(pair2);
    multimapExample.emplace(pair3);
    multimapExample.emplace(pair4);
    multimapExample.emplace("Test", 8); // key "Test" already inserted, can't insert another pair with key "Test"
    // multimapExample["Test"] = 10; // can't access by [] or at()
    itMultimap = multimapExample.find("Test"); // first iterator with key "Test"
    sresult = itMultimap->first;
    iresult = itMultimap->second;
    if(multimapExample.find("David") != multimapExample.end()) { //found
        iresult = multimapExample.count("David");
        multimapExample.erase("David");
    }
    iresult = multimapExample.count("TT");

    // set key = value
    vector<vector<string>> orders = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},
                        {"David","3","Fried Chicken"},{"Carla","5","Water"},
                        {"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    std::set<string> foodList;
    std::map<int, std::map<string, int>> tableList;
    vector<vector<string>> orderAns;
    for (auto& o :orders) {
        foodList.insert(o[2]); // o: {"David","3","Ceviche"}
        tableList[stoi(o[1])][o[2]]++; // tableList[3]: map<string, int>; tableList[3]["Ceviche"]: int number
    }
    for (auto& p :tableList) {
        vector<string> t = {to_string(p.first)}; // p.first : int number
        for (auto& s : foodList) {
            t.push_back(to_string(p.second[s])); // p.second: map<string, int>
        }
        orderAns.push_back(t);
    }

/********** unordered associative container **********/
    // unordered map
    unordered_map<string, int> map = {
        {"a", 1},
        {"b", 2},
        {"c", 3},
        {"d", 4}
    };
    map.insert({"e", 5});
    pair<string, int> insertMap = {"f", 6};
    map["g"] = 7; // if {"g", 7} not exist, create new
    map.at("h") = 8; // can't access if key "h" not exist
    map.insert(insertMap);
    map.emplace(insertMap);
    unordered_map<string, int>::iterator got;
    got = map.find("b");
    if (got != map.end()) {
        map.erase(got);
    }
    iresult = map.count("f");

    // unordered set
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    ListNode* iterA = headA;
    ListNode* iterB = headB;
    unordered_set<ListNode*> set = {headA, headB, iterA, iterB};
    while (iterA) {
        set.insert(iterA);
        iterA = iterA->next;
    }
    set.erase(iterA);
    while (iterB) {
        if (!set.empty() && set.find(iterB) != set.end()) {
            iresult = set.count(iterB); // if found iterB in set, iresult = 1, otherwise iresult = 0;
        }
        iterB = iterB->next;
    }

#endif // BASIC_DATA_STRUCTURE

#ifdef BASIC_ALOGO
    int numsExample{] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* p;
    p = find(numsExample, numsExample + 4, 6); // find in [0, 4), if not found, return last
    bool hasSearched = binary_search(numsExample, numsExample + 4, 5); // search in [0, 4) true if searched,false if not searched
    // lower_bound(first,last,target) in [first, last), the first element which >= target, if not found, return last
    // upper_bound(first,last,target) in [first, last), the first element which > target
    vector<int> vec(numsExample, numsExample + 9);
    vector<int>::iterator low, up;
    vec.insert(vec.begin()+ 5, 6);
    vec.insert(vec.begin() + 5, 6);
    low = lower_bound(vec.begin(), vec.end(), 6);
    up = upper_bound(vec.begin(), vec.end(), 6);
    int pos = low - vec.begin();
    pos = up - vec.begin();
    low = lower_bound(vec.begin(), vec.end(), 10);
    pos = low - vec.begin();
    low = lower_bound(vec.begin(), vec.end(), 0);
    pos = low - vec.begin();
    up = upper_bound(vec.begin(), vec.end(), 10);
    pos = up - vec.begin();
    up = upper_bound(vec.begin(), vec.end(), 0);
    pos = up - vec.begin();
#endif // BASIC_ALOGO

#ifdef ALGO_PATTERN
#ifdef ALGO_LINKED_LIST
// remove duplicates from sorted list
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while(cur != NULL && cur->next != NULL) {
            if(cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }

// remove all duplicate nodes from sorted list
    ListNode* deleteDuplicates2(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        int temp;
        while(head->next != NULL && head->next->next != NULL) {
             if(head->next->val == head->next->next->val) {
                 temp = head->next->val;
                 while(head->next != NULL && head->next->val == temp){
                     head->next = head->next->next;
                 }
             } else {
                 head = head->next;
             }
        }
        return dummy->next;
    }

// reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL)
        {
            ListNode *lat = cur->next;
            cur->next = pre;
            pre = cur;
            cur = lat;
        }
        return pre;
    }

// reverse linked list [1,2,...,m,...,n,...] between m, n
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        dummy->next = head;

        for(int i = 0; i < m - 1; i++){
           pre = pre->next;
        }
        //pre->next <=> pre->next->next
        ListNode *cur = pre->next;
        for(int i = m; i < n; i++){
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }

// merge two sorted list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

// sort list
// 1. split left, middle
// 2. sort left, middle
// 3. sort bigger left, middle
    ListNode * sortList(ListNode * head)
    {
        return  (head == NULL)? NULL: mergeSort(head);
    }

    // [1,2,3,4,5]: slow->3
    // [1,2,3,4,5,6]: slow->4
    ListNode * findMid(ListNode * head)
    {
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * previous = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // split the list into two parts
        previous->next = NULL;
        return slow;
    }

    ListNode * mergeSort(ListNode * head)
    {
        if (head->next == NULL) return head;
        ListNode * mid = findMid(head);
        ListNode * l1 = mergeSort(head);
        ListNode * l2 = mergeSort(mid);
        return mergeTwoLists(l1, l2);
    }

// judge cycle list
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            if(fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }

// detect cycle list
    ListNode *detectCycle(ListNode *head) {
        if (!hasCycle(head)) {
            return nullptr;
        }
        ListNode* ans;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
#endif // ALGO_LINKED_LIST

#ifdef ALGO_SEARCH
class Solution {
public:
    // binary_search
    int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target) {
            start = mid;
        } else {
            end = mid;
        }
    }
    // 2 candidates
    if (nums[start] == target ){
        return start;
    }
    if (nums[end] == target) {
        return end;
    }
    return -1;
    }

    // bfs
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> que;
        que.emplace(root) ;
        int depth = 1;
        while(!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr) {
                return depth;
                }
                if (node->left != nullptr) {
                    que.emplace(node->left);
                }
                if (node->right != nullptr) {
                    que.emplace(node->right);
                }
            }
            depth++;
        }
        return depth;
    }

    // preorder
    vector<int> nums;
    void preorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return nums;
    }

    // inorder
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return nums;
    }

    // recursion(dfs)
    void generate(int level, int max, vector<string>& str, string tmpstr) {
        // terminator
        if ( level > max ) {
            str.push_back(tmpstr);
            return;
        }

        // process current logic
        string s1 = tmpstr + "(";
        string s2 = tmpstr + ")";

        // drill down
        generate(level + 1, max, str, s1);
        generate(level + 1, max, str, s2);

        // restore current status
    }

    vector<string> generateParenthesis(int n) {
        vector<string> str;
        generate(0, n, str, "");
        return str;
    }
};
#endif // ALGO_SEARCH


#ifdef ALGO_SLIDING_WINDOW
class Solution {
public:

    // s="adobecodebanc" t="abc" "banc"
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            char c = s[right];
            // 右移窗口
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {
                // 在这里更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d 是将移出窗口的字符
                char d = s[left];
                // 左移窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        // 返回最小覆盖子串
        return len == INT_MAX ?
            "" : s.substr(start, len);
    }

    // s = "eidbaooo" t = "ab" true
    bool checkInclusion(string t, string s) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            while (right - left >= t.size()) {
                // 在这里判断是否找到了合法的子串
                if (valid == need.size())
                    return true;
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        // 未找到符合条件的子串
        return false;
    }

    // s = "cbaebabacd" t = "abc" [0,6]
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res; // 记录结果
        while (right < s.size()) {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            // 判断左侧窗口是否要收缩
            while (right - left >= t.size()) {
                // 当窗口符合条件时，把起始索引加入 res
                if (valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }

    // longest substring without repeating
    // s="abcabcbb" 3
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int res = 0; // 记录结果
        while (right < s.size()) {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            window[c]++;
            // 判断左侧窗口是否要收缩
            while (window[c] > 1) {
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                window[d]--;
            }
            // 在这里更新答案
            res = max(res, right - left);
        }
        return res;
    }

};




#endif //ALGO_SLIDING_WINDOW

#endif // ALGO_PATTERN