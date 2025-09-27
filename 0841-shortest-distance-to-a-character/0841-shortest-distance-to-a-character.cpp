class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> answer(n,n);//n is max possible distance
        int prev=-n;  //store last seen position of c

        //pass1: left to right
        for(int i=0;i<n;i++){
            if(s[i]==c)prev=i;
            answer[i]=i-prev;
        }

        prev=2*n;//reset for rights

        //pass2: right to left

        for(int i=n-1;i>=0;i--){
            if(s[i]==c)prev=i;
            answer[i]=min(answer[i],prev-i);
        }
        return answer;
    }
};