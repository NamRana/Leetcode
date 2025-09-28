/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)return 0;//base case is empty tree

        int depth=0;

        //exploring all children
        for(Node* child:root->children){
            depth=max(depth,maxDepth(child));
        }
        return depth+1;
    }
};