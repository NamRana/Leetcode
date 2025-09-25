class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ar;//convert all numbers into string
        for(int num:nums){
            ar.push_back(to_string(num));
        }

        //custom sort: compare concateneated results
        sort(ar.begin(),ar.end(),[](string &a,string &b){
            return a+b>b+a;
        });

        //edge case: if the largest number is "0", then entire number is 0
        if(ar[0]=="0")return "0";

        //concatenate result
        string result;
        for(string &s: ar)result+=s;

        return result;

    }
};