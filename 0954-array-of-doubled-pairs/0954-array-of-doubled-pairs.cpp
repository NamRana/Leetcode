#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {

        // Frequency map
        unordered_map<int, int> freq;
        for (int x : arr)
            freq[x]++;

        // Sort array by absolute value
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        // Try pairing each number with its double
        for (int x : arr) {
            if (freq[x] == 0)
                continue;  // Already used

            if (freq[2 * x] == 0)
                return false;  // No matching double

            // Use one x and one 2x
            freq[x]--;
            freq[2 * x]--;
        }

        return true;
    }
};
