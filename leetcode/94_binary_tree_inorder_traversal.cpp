/**
 * 94. Binary Tree Inorder Traversal
 * Difficulty: Easy
 *
 * Approach:
 * - Use dfs recursive call function
 *
 * Time:  O(n)
 * Space: O(h) - h = the height of the tree
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ve{};
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        ve.push_back(node->val);
        dfs(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return ve;
        dfs(root);
        return ve;
    }
};
