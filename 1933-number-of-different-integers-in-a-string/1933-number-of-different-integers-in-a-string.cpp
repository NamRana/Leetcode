class Solution {
public:
    int numDifferentIntegers(string word) {
        //replacing letters with space
        for(char &c:word){
            if(!isdigit(c))c=' ';
        }

        unordered_set<string> st;
        stringstream ss(word);
        string num;

        //split numbers by space
        while(ss>>num){
            //remove leading zeroes
            int i=0;
            while(i<num.size()&&num[i]=='0')i++;
            string cleanNum=num.substr(i);
            if(cleanNum=="")cleanNum="0";
            st.insert(cleanNum);
        }
        return st.size();
    }
};