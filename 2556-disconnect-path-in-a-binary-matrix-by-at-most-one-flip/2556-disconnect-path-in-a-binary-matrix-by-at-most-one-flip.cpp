class Solution {
public:
    int m,n;
    vector<vector<int>> dirs={{1,0},{0,1}};

    bool dfs(int r, int c, vector<vector<int>> &grid, vector<pair<int,int>>& path){
        if(r==m-1 &&c==n-1){
            path.push_back({r,c});
            return true;
        }

        grid[r][c]=0;

        for(auto &d:dirs){
            int nr=r+d[0];
            int nc=c+d[1];
            if(nr>=0&&nc>=0&&nr<m&&nc<n&&grid[nr][nc]==1){
                if(dfs(nr,nc,grid,path)){
                    path.push_back({r,c});
                    return true;
                }
            }
        }
        return false;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<pair<int,int>> path;

        vector<vector<int>> temp=grid;
        if(!dfs(0,0,temp,path)){
            return true;
        }

        for(auto &p:path){
            if((p.first==0 && p.second==0)||(p.first==m-1 && p.second==n-1)){continue;}
            grid[p.first][p.second]=0;
        }

        return !dfs(0,0,grid,path={});
    }
};