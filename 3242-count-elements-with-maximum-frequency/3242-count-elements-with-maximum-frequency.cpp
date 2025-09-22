class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n:nums){
            freq[n]++;
        }

        int mx=0;
        for(auto [num,frequency]:freq){
            mx=max(mx,frequency);
        }

        int freqs=0;
        for(auto [num,frequency]:freq){
            if(frequency==mx){
                freqs++;
            }
        }

        return freqs*mx;
    }
};