/* leetcode 404
 *
 *
 *
 */
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int travel(TreeNode* tmp) {
        if (tmp == nullptr) {
            return 0;
        }
        int ans = 0;
        if (tmp->left != nullptr && tmp->left->left == nullptr && tmp->left->right == nullptr) {
            ans += tmp->left->val;
        }
        ans += travel(tmp->left);
        ans += travel(tmp->right);
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        ans = travel(root);
        return ans;
    }
};


/**************************   run solution   **************************/
int _solution_run(TreeNode* root)
{
    Solution leetcode_404;
    return leetcode_404.sumOfLeftLeaves(root);
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