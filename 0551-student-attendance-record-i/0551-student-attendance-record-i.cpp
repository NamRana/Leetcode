class Solution {
public:
    bool checkRecord(string s) {
        int absents=0; //counting for A
        int conL=0; //counting for L

        for (char c:s){
            if(c=='A'){
                absents++;
                if(absents>=2)return false;
                conL=0; //reset L
            }

            else if(c=='L'){
                conL++;
                if(conL>=3)return false;
            }

            else{
                conL=0;
            }
        }
        return true;
    }
};