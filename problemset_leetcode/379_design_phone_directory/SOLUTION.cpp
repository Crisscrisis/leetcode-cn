/* leetcode 379
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
using namespace std;

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        direct.resize(maxNumbers, true);
        size = maxNumbers;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for (int i = 0; i < size; i++) {
            if (direct[i] == true) {
                direct[i] = false;
                return i;
            }
        }
        return -1;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (number > size - 1 || number < 0) {
            return false;
        }
        return direct[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < size) {
            direct[number] = true;
        }
    }
private:
    vector<bool> direct;
    int size;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

#define USE_SOLUTION_CUSTOM

/**************************   run solution   **************************/
void _solution_run(int n)
{
    return ;
}

#ifdef USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
    vector<string> ans;
    PhoneDirectory* obj = nullptr;
    for(size_t i = 0; i < sf.size(); i++) {
        if(sf[i] == "PhoneDirectory") {
            TestCases stc(sp[i]);
            int capacity = stc.get<int>();
            obj = new PhoneDirectory(capacity);
            ans.push_back("null");
        } else if(sf[i] == "get") {
            int ret = obj->get();
            ans.push_back(convert<string>(ret));
        } else if(sf[i] == "check") {
            TestCases stc(sp[i]);
            int key = stc.get<int>();
            int ret = obj->check(key);
            ans.push_back(convert<string>(ret));
        } else if(sf[i] == "release") {
            TestCases stc(sp[i]);
            int key = stc.get<int>();
            obj->release(key);
            ans.push_back("null");
        }
    }

    delete obj;
	return convert<string>(ans);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif