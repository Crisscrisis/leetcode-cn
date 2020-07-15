/* leetcode 11
 *
 *
 *
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l, r, width, minIdx;
        l = 0;
        r = height.size() - 1;
        int maxArea = 0;
        while(l < r) {
            if (height.at(l) < height.at(r)) {
                width = r - l;
                maxArea = max(maxArea, height.at(l) * width);
                l++;
            } else {
                width = r - l;
                maxArea = max(maxArea, height.at(r) * width);
                r--;
            }
        }
        return maxArea;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& height)
{
    Solution leetcode_11;
    int ans = leetcode_11.maxArea(height);
    return ans;
}

#ifdef USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    string list = tc.get<string>();
    int n = tc.get<int>();
    ListNode *head = StringToListNode(list);
    Solution leetcode_19;
    ListNode *ans = leetcode_19.removeNthFromEnd(head, n);
    if (ans == nullptr) {
        return "null";
    } else {
        return ListNodeToString(ans);
    }
}
#endif

/**************************   get testcase   **************************/
#ifdef USE_GET_TEST_CASES_IN_CPP
vector<string> _get_test_cases_string()
{
    return {};
}
#endif