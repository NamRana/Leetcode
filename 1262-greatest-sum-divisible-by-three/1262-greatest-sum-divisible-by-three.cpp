class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> rem1, rem2;

        // Separate numbers based on remainder
        for (int x : nums) {
            total += x;
            if (x % 3 == 1) rem1.push_back(x);
            else if (x % 3 == 2) rem2.push_back(x);
        }

        // Sort to find smallest elements
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        // If already divisible by 3
        if (total % 3 == 0) return total;

        int remove1 = INT_MAX, remove2 = INT_MAX;

        // Case 1: total % 3 == 1 → remove 1 (mod 1) OR 2 (mod 2)
        if (total % 3 == 1) {

            if (!rem1.empty()) remove1 = rem1[0];            // remove 1 mod1
            if (rem2.size() >= 2) remove2 = rem2[0] + rem2[1]; // OR remove 2 mod2

        }

        // Case 2: total % 3 == 2 → remove 1 (mod 2) OR 2 (mod 1)
        else { // total % 3 == 2

            if (!rem2.empty()) remove1 = rem2[0];             // remove 1 mod2
            if (rem1.size() >= 2) remove2 = rem1[0] + rem1[1];  // OR remove 2 mod1

        }

        int cut = min(remove1, remove2);
        if (cut == INT_MAX) return 0;

        return total - cut;
    }
};
