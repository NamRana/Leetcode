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
    int cameras = 0;

    // Returns:
    // 0 -> node is NOT covered
    // 1 -> node has a camera
    // 2 -> node is covered
    int dfs(TreeNode* node) {
        if (!node) return 2;  // null nodes are considered covered

        int left = dfs(node->left);
        int right = dfs(node->right);

        // If any child is not covered, place a camera here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;  // this node has a camera
        }

        // If any child has a camera, this node is covered
        if (left == 1 || right == 1) {
            return 2;  // covered
        }

        // Otherwise, this node is not covered
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {  // if root is not covered
            cameras++;
        }
        return cameras;
    }
};
