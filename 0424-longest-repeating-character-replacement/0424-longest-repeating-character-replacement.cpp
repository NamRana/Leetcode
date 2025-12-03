class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left=0,right=0;
        int maxFreq=0;
        int ans=0;

        while(right<s.size()){
            //increase frequesny of current char
            freq[s[right]-'A']++;

            //update max frequency in current window
            maxFreq=max(maxFreq,freq[s[right]-'A']);

            //if window is invalid->shrink from left
            while((right-left+1)-maxFreq>k){
                freq[s[left]-'A']--;
                left++;
            }

            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};