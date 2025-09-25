class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> mask(n,0);
        vector<int> length(n,0);

        //creating bitmasks
        for(int i=0;i<n;i++){
            int bitmask=0;
            for(char c:words[i]){
                bitmask|=(1<<(c-'a'));//setting bit for character
            }
            mask[i]=bitmask;
            length[i]=words[i].size();
        }

        int maxProd=0;

        //comparing pairs
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i]&mask[j])==0){
                    maxProd=max(maxProd, length[i]*length[j]);
                }
            }
        }
        return maxProd;
    }
};