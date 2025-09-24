class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jset(jewels.begin(),jewels.end());
        int count=0;

        for(char stone:stones){
            if(jset.count(stone)){
                count++;
            }
        }
        return count;
    }
};