class Solution {
public:
    long long total = 0, maxProductVal = 0;
    const int MOD = 1e9 + 7;

    long long totalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long subtreeSum(TreeNode* root) {
        if (!root) return 0;
        long long s = root->val + subtreeSum(root->left) + subtreeSum(root->right);
        maxProductVal = max(maxProductVal, s * (total - s));
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = totalSum(root);
        subtreeSum(root);
        return maxProductVal % MOD;
    }
};
