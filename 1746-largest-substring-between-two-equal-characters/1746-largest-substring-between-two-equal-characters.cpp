class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        //Map to store the first occurence for each character
        vector<int> first(26,-1);
        int maxLen=-1; //default setting to -1 if not valid substring is present

        for(int i=0;i<s.size();i++){

            int idx=s[i]-'a';

            if(first[idx]==-1){
                first[idx]=i;
            }else{
                maxLen=max(maxLen,i-first[idx]-1);
            }
        }
        return maxLen;
    }
};