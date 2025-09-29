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
    int dfs(TreeNode* node,int cur){
        if(!node)return 0;

        cur=(cur<<1)|node->val;

        if(!node->left&&!node->right){return cur;}

        return dfs(node->left,cur)+dfs(node->right,cur);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);//starting DFS with inital value 0
    }
};