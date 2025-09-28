class Solution {
public: 
    vector<vector<int>> graph; //all richer than B
    vector<int> answer; //quietest person for each node
    vector<int> quiet; //quietness array

    //DFS function: returns the quitest person richer or equal to person

    int dfs(int person){
        if(answer[person]!=-1)return answer[person];

        //intially assume that the quitest is the person themselves
        int quietest=person;

        //explore all people richer than current person
        for(int richerPerson:graph[person]){
            int candidate=dfs(richerPerson);

            //compare quietness values
            if(quiet[candidate]<quiet[quietest]){
                quietest=candidate;
            }
        }

        //storing results in memo array
        answer[person]=quietest;
        return quietest;
    }


vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quietInput) {
        int n = quietInput.size();
        quiet = quietInput;

        graph.resize(n);
        answer.assign(n, -1);  // initialize all as uncomputed

        // Build graph:
        // richer[i] = [a, b] means a is richer than b → edge: b → a
        for (auto& r : richer) {
            int a = r[0], b = r[1];
            graph[b].push_back(a);
        }

        // Run DFS for every person
        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        return answer;
    }
};