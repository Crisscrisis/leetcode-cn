/* leetcode 486
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
    vector<vector<int>> mem;    // mem[left][right]: biggest numbers we can get in situation nums[left, right]
    vector<int> sum;    // sum[n]: sum between nums[0, n]

    int helper(vector<int>& nums, int left, int right) { // biggest numbers in situation nums[left, right]
        if (left == right) {
            return nums[left];
        }

        if (mem[left][right] != -1)
            return mem[left][right];

        int total = sum[right] - sum[left] + nums[left];    // sum between nums[left, right]
        int ans = max(total - helper(nums, left + 1, right),    // if we i chose left, then you will get the biggest numbers in situation nums[left + 1, right]
                                                                // thus, the present numbers we get is total - helpers(nums, left + 1, right)
                        total - helper(nums, left, right-1));   // if we i chose right, then you will get the biggest numbers in situation nums[left, right - 1]
                                                                // thus, the present numbers we get is total - helpers(nums, left, right - 1)
        return mem[left][right] = ans;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        mem.resize(n, vector<int>(n, -1));
        sum.resize(n);
        int t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            t += nums[i];
            sum[i] = t;
        }
        int total = sum.back();
        int maxV = helper(nums, 0, n-1);
        return maxV >= total-maxV;
    }
};


/**************************   run solution   **************************/
bool _solution_run(vector<int>& nums)
{
    Solution leetcode_486;
    bool ans = leetcode_486.PredictTheWinner(nums);
    return ans;
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