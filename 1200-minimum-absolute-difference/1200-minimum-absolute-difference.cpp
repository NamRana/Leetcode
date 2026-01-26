class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int mindiff=INT_MAX;

        for(int i=1;i<arr.size();i++){
            mindiff=min(mindiff,arr[i]-arr[i-1]);
        }

        vector<vector<int>> result;

        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==mindiff){
                result.push_back({arr[i-1],arr[i]});
            }
        }
        return result;
    }
};