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
    int maxDepth=0;
    int sum=0;

    void dfs(TreeNode* node, int depth){
        if(!node)return;

        if(depth>maxDepth){
            maxDepth=depth;
            sum=node->val;//resetting sum
        }
        else if(depth==maxDepth){
            sum+=node->val;
        }

        dfs(node->left,depth+1);
        dfs(node->right,depth+1);

    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};