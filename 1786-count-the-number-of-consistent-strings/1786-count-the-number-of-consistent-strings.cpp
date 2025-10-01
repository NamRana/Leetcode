class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        //storing allowed character in a set
        unordered_set<char> allowedSet(allowed.begin(),allowed.end());
         int count=0;

         //checking each word
         for(string &word:words){
            bool isCons=true;

            for(char c:word){
                if(allowedSet.find(c)==allowedSet.end()){
                    isCons=false;
                    break;
                }
            }
            if(isCons)count++;
         }
         return count;
    }
};