class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> freq;//counting freq of each number in arr1
        for(int num:arr1){
            freq[num]++;
        }
        vector<int> result;

        //placing numbers according to the arr2 order
        for(int num: arr2){
            while(freq[num]>0){
                result.push_back(num);//appending num
                freq[num]--;
            }
            freq.erase(num);
        }

        //processing remaining numbers
        vector<int> remaining;
        for(auto &[num,count]:freq){
            for(int i=0;i<count;i++){
                remaining.push_back(num);
            }
        }

        sort(remaining.begin(),remaining.end()); //ascending order

        //appending reamining numbers
        result.insert(result.end(),remaining.begin(),remaining.end());

        return result;

    }
};