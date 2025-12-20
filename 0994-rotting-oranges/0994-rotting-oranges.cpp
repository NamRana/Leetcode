class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        queue<pair<int,int>> q;
        int fresh=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        if(fresh==0)return 0;
        int min=0;

        //BFS traversal
        while(!q.empty()){
            int size=q.size();
            bool rotminute=false;

            //process one BFS level
            for(int i=0;i<size;i++){
                auto[x,y]=q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int nx=x+dx[d];
                    int ny=y+dy[d];

                    if(nx>=0&&ny>=0&&nx<rows&&ny<cols&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                        rotminute=true;
                    }
                }
            }
            if(rotminute)min++;
        }
        return fresh==0? min:-1;

    }
};