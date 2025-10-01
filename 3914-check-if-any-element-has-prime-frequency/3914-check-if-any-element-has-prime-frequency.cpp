class Solution {
public:

    //helper function is check prime
    bool isPrime(int n){
        if(n<=1)return false;
        if(n==2)return true;
        if(n%2==0)return false;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0)return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;

        //count frequency of each element
        for(int num:nums){
            freq[num]++;
        }

        //checking if the frequency is prime
        for(auto &p:freq){
            if(isPrime(p.second)){
                return true;
            }
        }
        return false;
    }
};