class Solution {
public:
    int totalMoney(int n) {
         int weeks = n / 7;   // Number of complete weeks
        int days = n % 7;    // Remaining days in the current (incomplete) week

        // 1️⃣ Calculate total for complete weeks
        // Each week forms an arithmetic progression:
        // Week 1 sum = 28, Week 2 = 35, Week 3 = 42 ...
        // So: 28 + 35 + 42 + ... = 28 * weeks + 7 * (sum of 0 to weeks-1)
        // Sum of first (weeks-1) numbers = (weeks - 1) * weeks / 2
        int total = (28 * weeks) + (7 * (weeks * (weeks - 1) / 2));

        // 2️⃣ Add the remaining days
        // Next week starts with (1 + weeks)
        for (int i = 0; i < days; ++i) {
            total += (weeks + 1 + i);
        }

        return total;
    }
};