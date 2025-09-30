class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int count=0;

        for(int i=0;i<n;i++){
            int left=(i-1+n)%n; //previous tile (wrap around)
            int mid=i; //current tile
            int right=(i+1+n)%n; //next tile (wrap around)
            
            //middle tile will be different from both neighbors
            if(colors[mid]!=colors[left]&&colors[mid]!=colors[right]){
                count++;
            }

        }
        return count;
    }
};