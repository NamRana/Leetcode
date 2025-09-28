class Solution {
public:

    vector<vector<int>> adj;
    vector<bool> visited;
    bool dfs(int node,int destination){
        if(node==destination)return true;

        visited[node]=true;

        for(int n:adj[node]){
            if(!visited[n]){
                if(dfs(n,destination))return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n);
        visited.resize(n,false);

        //Build adjaceny list
        for(auto& e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(source,destination);
    }
};