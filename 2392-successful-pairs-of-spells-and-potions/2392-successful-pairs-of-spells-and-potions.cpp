class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         sort(potions.begin(), potions.end());
    int m = potions.size();
    vector<int> result;

    for (int spell : spells) {
        // Minimum potion needed
        long long required = (success + spell - 1) / spell;  // ceil(success / spell)
        auto it = lower_bound(potions.begin(), potions.end(), required);
        int count = potions.end() - it;  // Successful pairs count
        result.push_back(count);
    }

    return result;
    }
};