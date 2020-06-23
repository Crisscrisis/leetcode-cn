/* leetcode 189
 *
 *
 *
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) {
            return;
        }
        int len = nums.size();
        k = k % len;
        int start = 0;
        int tmp = 0;
        for (int cnt = 0; cnt < len; start++) {
            int current = start;
            int pre = nums.at(current);
            do {
                int next = (current + k) % len;
                int tmp = nums.at(next);
                nums.at(next) = pre;
                current = next;
                pre = tmp;
                cnt++;
            } while (current != start);
        }
    }
};


/**************************   run solution   **************************/
vector<int> _solution_run(vector<int>& nums, int k)
{
    Solution leetcode_189;
    leetcode_189.rotate(nums, k);
    return nums;
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