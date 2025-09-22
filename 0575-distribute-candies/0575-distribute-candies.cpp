class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;

        for(int c:candyType){
            types.insert(c);
        }

        int n=candyType.size()/2;

        return min((int)types.size(),n);
    }
};