class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;

        for(string op:ops){
            if(op=="C"){
                record.pop_back();
            }
            else if(op=="D"){
                record.push_back(2* record.back());
            }
            else if(op=="+"){
                int n=record.size();
                record.push_back(record[n-1]+record[n-2]);
            }
            else {
                record.push_back(stoi(op));
            }
        }
        int total=0;
        for(int score:record){
            total+=score;
        }
        return total;
    }
};