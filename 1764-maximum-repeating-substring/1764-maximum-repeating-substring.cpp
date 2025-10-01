class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k=1;
        string repeated=word;

        //keep repeating while it is a substring
        while(sequence.find(repeated)!=string::npos){
            k++;
            repeated+=word;
        }
        return k-1;
    }
};