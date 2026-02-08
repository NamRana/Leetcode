class Solution {
public:
    // Helper function to check height
    int height(TreeNode* root) {
        // Base case: empty tree
        if (root == NULL)
            return 0;

        // Check left subtree
        int leftHeight = height(root->left);
        if (leftHeight == -1) 
            return -1; // left subtree unbalanced

        // Check right subtree
        int rightHeight = height(root->right);
        if (rightHeight == -1) 
            return -1; // right subtree unbalanced

        // If current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height if balanced
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
