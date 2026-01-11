class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;

        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            vector<TreeNode*> parents;

            // Collect parents and compute sum of next level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                parents.push_back(node);

                if (node->left)  levelSum += node->left->val;
                if (node->right) levelSum += node->right->val;
            }

            // Update children values
            for (TreeNode* parent : parents) {
                int siblingSum = 0;
                if (parent->left)  siblingSum += parent->left->val;
                if (parent->right) siblingSum += parent->right->val;

                if (parent->left) {
                    parent->left->val = levelSum - siblingSum;
                    q.push(parent->left);
                }
                if (parent->right) {
                    parent->right->val = levelSum - siblingSum;
                    q.push(parent->right);
                }
            }
        }
        return root;
    }
};
