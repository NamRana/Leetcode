class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0, sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // shrink window if sum too large
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // found a valid subarray
            if (sum == target) {
                int len = right - left + 1;

                // if there's a valid subarray before this
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // update best at this position
                best[right] = min((right > 0 ? best[right - 1] : INF), len);
            } else {
                // carry forward previous best
                best[right] = (right > 0 ? best[right - 1] : INF);
            }
        }

        return ans == INF ? -1 : ans;
    }
};
