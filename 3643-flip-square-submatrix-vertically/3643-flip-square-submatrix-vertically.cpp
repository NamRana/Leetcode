class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        //iterating for the first half of the matrix
        for(int i=0;i<k/2;i++){
            int row1=x+i;
            int row2=x+k-1-i;

            //swapping elements in the same column
            for(int j=0;j<k;j++){
                swap(grid[row1][y+j],grid[row2][y+j]);
            }
        }
        return grid;
    }
};