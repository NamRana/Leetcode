class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator ==0) return "0";

        string res;
        if((numerator<0)^(denominator<0))res+="-";

        long long num=llabs((long long)numerator);
        long long den=llabs((long long)denominator);

        res+=to_string(num/den);
        long long remainder=num%den;

        if(remainder==0)return res;
        res+=".";

        unordered_map<long long, int> remainderMap;

        while(remainder){
            if(remainderMap.find(remainder)!=remainderMap.end()){
                res.insert(remainderMap[remainder], "(");
                res+=")";
                break;
            }

            remainderMap[remainder]=res.size();
            remainder*=10;
            res+=to_string(remainder/den);
            remainder%=den;
        }
        return res;
   }
};