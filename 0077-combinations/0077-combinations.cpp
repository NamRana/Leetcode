class Solution {
public:
    vector<vector<int>> result;
    vector<int> cur;

    void backtrack(int start,int n,int k){
        //if combination size is k, add to result
        if(cur.size()==k){
            result.push_back(cur);
            return;
        }

        //try all possible numbers from start to n
        for(int i=start;i<=n;i++){
            cur.push_back(i);
            backtrack(i+1,n,k);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,k);
        return result;
    }
};