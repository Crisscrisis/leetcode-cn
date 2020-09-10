/* leetcode 406
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
using namespace std;

class Solution {
public:
    static bool cmpVec(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        } else {
            return a[0] > b[0];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty()) {
            return people;
        }
        sort(people.begin(), people.end(), cmpVec);
        int len = people.size();
        list<vector<int>> tmp;
        for (int i = 0; i < len; i++) {
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        return vector<vector<int>> (tmp.begin(), tmp.end());
    }
};


/**************************   run solution   **************************/
vector<vector<int>> _solution_run(vector<vector<int>>& people)
{
    Solution leetcode_46;
    return leetcode_46.reconstructQueue(people);
}

#ifdef USE_SOLUTION_CUSTOM
vector<vector<int>> _solution_custom(TestCases &tc)
{
    return {};
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif