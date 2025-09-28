class Solution {
public:
        vector<int> parent; 
        vector<int> rank;

        //find operation with path compression
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);//compress path->flatten tree
            }
            return parent[x];
        }

        //union operation, return false if x and y are already connected
        bool unionSets(int x,int y){
            int rootX=find(x);
            int rootY=find(y);

            if(rootX==rootY){
                return false;//already connect this edge will form a cycle
            }

            //union by rank: attach smaller tree under bigger one
            if(rank[rootX]>rank[rootY]){
                parent[rootY]=rootX;
            }
            else if(rank[rootX]<rank[rootY]){
                parent[rootX]=rootY;
            }
            else{
                parent[rootY]=rootX;
                rank[rootX]++; //increase rank if both have same depth
            }
            return true;
        }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        parent.resize(n+1);
        rank.resize(n+1,1);

        //initially each node has its own parent
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        //process each edge
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            //if union fails->edge is creating a cycle->returnn it

            if(!unionSets(u,v)){
                return edge;
            }
        }
        return {};//should never reach here
        }
};