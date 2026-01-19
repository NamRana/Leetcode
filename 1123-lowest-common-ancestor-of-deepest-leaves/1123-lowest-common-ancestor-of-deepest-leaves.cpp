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
    
    // Helper function:
    // Returns a pair:
    // first  -> maximum depth of subtree rooted at this node
    // second -> LCA of deepest leaves in this subtree
    pair<int, TreeNode*> dfs(TreeNode* root) {
        
        // Base case: empty tree
        if (root == nullptr) {
            return {0, nullptr};
        }

        // Recursively get depth & LCA from left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If left subtree is deeper, propagate its LCA
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // If right subtree is deeper, propagate its LCA
        if (right.first > left.first) {
            return {right.first + 1, right.second};
        }

        // If both depths are equal:
        // current node is the LCA of deepest leaves
        return {left.first + 1, root};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // We only need the LCA node from the result
        return dfs(root).second;
    }
};
