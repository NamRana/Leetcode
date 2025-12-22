class Solution {
public:
    
    void backtrack(int index, vector<int>& candidates,
                   vector<int>& current, int target,
                   vector<vector<int>>& ans) {

        // Base case
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (target < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {

            current.push_back(candidates[i]);

            // Same number can be reused
            backtrack(i, candidates, current, target - candidates[i], ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> current;

        backtrack(0, candidates, current, target, ans);

        return ans;
    }
};
