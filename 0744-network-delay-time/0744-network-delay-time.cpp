class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &t:times){
            graph[t[0]].push_back({t[1],t[2]});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [time, node]=pq.top();
            pq.pop();

            for(auto [nei,w]:graph[node]){
                //If going through 'node' improves distance to 'nei'
                if(time+w<dist[nei]){
                    dist[nei]=time+w;
                    pq.push({dist[nei],nei});
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};