/**
 * 145. Binary Tree Postorder Traversal
 * Difficulty: Easy
 *
 * Approach:
 * - Use dfs recursive call function
 *
 * Time:  O(n)
 * Space: O(h) - h = the height of the tree, worst case O(n)
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
        dfs(node->right);
        ve.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return ve;
        dfs(root);
        return ve;
    }
};
