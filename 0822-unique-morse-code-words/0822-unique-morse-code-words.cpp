class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> transformation; //storing unique morse words

        //convert each word to its morse representation
        for(string word: words){
            string code="";
            for(char c:word){
                code+=morse[c-'a'];
            }
            transformation.insert(code);
        }

        return transformation.size();
    }
};