class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Step 1: Sort by end ascending, if tie then start descending
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        // These two represent the last two numbers selected in our set
        int first = -1, second = -1;
        int count = 0; // total numbers in the containing set

        for (auto &v : intervals) {
            int start = v[0];
            int end = v[1];

            // Case 1: Both selected numbers are outside interval
            if (first < start) {
                // Need to add 2 numbers: end - 1 and end
                count += 2;
                second = end - 1;
                first = end;
            }
            // Case 2: Only the larger number (first) is inside the interval
            else if (second < start) {
                // Need to add 1 number: end
                count += 1;
                second = first;
                first = end;
            }
            // Case 3: Both already cover interval → do nothing
        }

        return count;
    
    }
};