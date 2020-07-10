/* leetcode 42
 *
 *
 *
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        vector<int> lmax(height.size()), rmax(height.size());
        int water = 0;
        lmax.at(0) = height.at(0);
        rmax.at(height.size() - 1) = height.at(height.size() - 1);
        for (int l = 1; l < height.size(); l++) {
            lmax.at(l) = max(height.at(l), lmax.at(l-1));
        }
        for (int r = height.size() - 2; r >= 0; r--) {
            rmax.at(r) = max(height.at(r), rmax.at(r+1));
        }
        for(int i = 0; i < height.size(); i++) {
            water += min(lmax.at(i), rmax.at(i)) - height.at(i);
        }
        return water;
    }
};


/**************************   run solution   **************************/
int _solution_run(vector<int>& height)
{
    Solution leetcode_42;
    int ans = leetcode_42.trap(height);
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