class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10,0);

        //Handling the negtive number
        n=abs(n);

        //counting digit frequencies
        if(n==0)freq[0]=1;//special case: 0 itself
        while(n>0){
            int d=n%10;
            freq[d]++;
            n/=10;
        }

        int ans =-1,minFreq=INT_MAX;

        //finding least frequent digit(must appear at least once)
        for(int d=0;d<=9;d++){
            if(freq[d]>0){
                if(freq[d]<minFreq || (freq[d]==minFreq && d<ans)){
                    minFreq=freq[d];
                    ans=d;
                }
            }
        }
        return ans;
    }
};