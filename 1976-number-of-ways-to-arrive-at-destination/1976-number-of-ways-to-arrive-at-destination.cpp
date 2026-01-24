class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &r: roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;

        pq.push({0,0});

        while(!pq.empty()){
            auto [time,u]=pq.top();
            pq.pop();

            if(time>dist[u])continue;

            for(auto &[v,w]:adj[u]){
                long long newTime=time+w;

                if(newTime<dist[v]){
                    dist[v]=newTime;
                    ways[v]=ways[u];
                    pq.push({newTime,v});
                }
                else if(newTime==dist[v]){
                    ways[v]=(ways[v]+ways[u])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};