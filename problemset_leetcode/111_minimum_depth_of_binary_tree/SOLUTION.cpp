/* leetcode 111
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
#if 0
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, int>> que;
        que.emplace(root, 1) ;
        while(!que.empty()) {
            TreeNode* node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left != nullptr) {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                que.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
#endif
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
};


/**************************   run solution   **************************/
int _solution_run(TreeNode* root)
{
    Solution leetcode_111;
    return leetcode_111.minDepth(root);
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