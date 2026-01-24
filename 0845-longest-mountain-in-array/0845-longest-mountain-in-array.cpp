class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int ans = 0;
        int i = 1;

        while (i < n - 1) {
            // Check if arr[i] is a peak
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {

                int left = i - 1;
                int right = i + 1;

                // Move left while strictly increasing
                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--;
                }

                // Move right while strictly decreasing
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Update answer
                ans = max(ans, right - left + 1);

                // Skip processed elements
                i = right;
            } else {
                i++;
            }
        }
        return ans;
    }
};
