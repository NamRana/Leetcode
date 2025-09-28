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
    bool isSameTree(TreeNode* t1, TreeNode* t2){
        if(!t1&&!t2)return true; //if both are null then same
        if(!t1||!t2)return false; //one null->different
        if(t1->val!=t2->val)return false; //values differernt->different

        //recursively check left and right subtree
        return isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false; //reached leaf in root->no match

        //checking if subtree starting at current node matches
        if(isSameTree(root,subRoot))return true;

        //otherwise checking left and right subtree
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};