/* leetcode 88
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j = 0;
        for (i = m; i < nums1.size(); i++) {
            nums1.at(i) = nums2.at(j++);
        }
        sort(nums1.begin(), nums1.end());
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    Solution leetcode_88;
    leetcode_88.merge(nums1, m, nums2, n);
    return nums1;
}

#ifdef USE_SOLUTION_CUSTOM
ListNode* _solution_custom(TestCases &tc)
{

	return leetcode_2.addTwoNumbers(l1, l2);
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
	return {};
}
#endif