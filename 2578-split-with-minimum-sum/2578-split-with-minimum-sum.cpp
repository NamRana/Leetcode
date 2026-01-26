class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;
        while(num>0){
            digits.push_back(num%10);
            num/=10;
        }

        sort(digits.begin(),digits.end());

        int sum1=0;
        int sum2=0;

        for(int i=0;i<digits.size();i++){
            if(i%2==0){
                sum1=sum1*10+digits[i];
            }
            else{
                sum2=sum2*10+digits[i];
            }
        }
        return sum1+sum2;
    }
};