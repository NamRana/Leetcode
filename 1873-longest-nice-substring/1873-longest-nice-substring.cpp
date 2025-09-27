class Solution {
public:
    string longestNiceSubstring(string s) {
        //base case: string of length < 2 can never be nice
        if(s.size()<2)return "";

        //store all the data in a set
        unordered_set<char>  st(s.begin(),s.end());

        //check every char for string
        for(int i=0;i<s.size();i++){
            char c=s[i];

            //check if lowercase and uppercase both exist in the set
            if(st.count(tolower(c))&&st.count(toupper(c))){
                continue;
            }

            string left=longestNiceSubstring(s.substr(0,i));
            string right=longestNiceSubstring(s.substr(i+1));

            if(left.size()>=right.size())return left;
            else return right;
        }
        return s;
    }
};