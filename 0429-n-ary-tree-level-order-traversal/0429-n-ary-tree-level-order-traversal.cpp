class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;

        // Edge case: empty tree
        if (root == NULL) return result;

        queue<Node*> q;
        q.push(root);

        // BFS traversal
        while (!q.empty()) {
            int levelSize = q.size();   // number of nodes in this level
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();
                q.pop();

                // Add current node's value
                level.push_back(curr->val);

                // Push all children into queue
                for (Node* child : curr->children) {
                    q.push(child);
                }
            }

            // Store current level
            result.push_back(level);
        }

        return result;
    }
};
