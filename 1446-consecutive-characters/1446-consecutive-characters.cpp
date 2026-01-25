class Solution {
public:
    int maxPower(string s) {
        int maxCount=1;
        int currentCount=1;

        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                currentCount++;
            }else{
                currentCount=1;
            }

            maxCount=max(maxCount,currentCount);
        }
    return maxCount;
    }
};