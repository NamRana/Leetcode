class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task
        vector<int> freq(26, 0);
        for(char t : tasks)
            freq[t - 'A']++;

        // Step 2: Find the max frequency
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Step 3: Count how many tasks have max frequency
        int maxCount = 0;
        for(int f : freq)
            if(f == maxFreq) maxCount++;

        // Step 4: Apply the formula we derived
        int frame = (maxFreq - 1) * (n + 1) + maxCount;

        // Step 5: The answer must be at least total number of tasks
        return max((int)tasks.size(), frame);
    }
};
