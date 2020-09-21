## leetcode404 左叶子之和

### 思路
```
遍历左右节点，遍历过程中判断，如果当前节点为空，则终止遍历，否则如果满足左叶子条件，则记录左叶子值，将该值传出。
```

### code
```c++
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
```