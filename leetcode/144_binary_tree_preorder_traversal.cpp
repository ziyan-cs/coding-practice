/**
 * 144. Binary Tree Preorder Traversal
 * Difficulty: Easy
 *
 * Approach: Iterative traversal using stack
 * - Use a stack to simulate the recursion call stack
 * - Push the right child first, then the left child (to ensure preorder order)
 * - Pop the top node, visit it, then push its children
 *
 * Time:  O(n)
 * Space: O(n)
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ve{};
        if (!root) return ve;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();

            ve.push_back(temp->val);

            if (temp->right) st.push(temp->right);
            if (temp->left) st.push(temp->left);
        }
        return ve;
    }
};
