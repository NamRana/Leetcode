class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> indexMap;
        for (int i=0;i<list1.size();i++){
            indexMap[list1[i]]=i;
        }

        vector<string> result;
        int minSum=INT_MAX;

        for(int j=0;j<list2.size();j++){
            string s=list2[j];

            if(indexMap.find(s)!=indexMap.end()){
                int i=indexMap[s];
                int indexSum=i+j;

                if(indexSum<minSum){
                    result.clear();
                    result.push_back(s);
                    minSum=indexSum;
                }

                else if(indexSum==minSum){
                    result.push_back(s);
                }
            }
        }
        return result;
    }
};