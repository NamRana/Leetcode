class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY = 0;
        for (char c : customers)
            if (c == 'Y') totalY++;

        int penalty = totalY;   // closing at hour 0
        int minPenalty = penalty;
        int bestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y')
                penalty--;   // avoided closed-hour penalty
            else
                penalty++;   // added open-hour penalty

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
    }
};
