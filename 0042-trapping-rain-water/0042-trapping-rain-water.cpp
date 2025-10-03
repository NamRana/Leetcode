class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;

        vector<int> leftMax(n), rightMax(n);

        //computing left max for each index
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }

        //computing rightmax for each index
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }

        //calculating water trapped
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(leftMax[i],rightMax[i])-height[i];
        }

        return water;
    }
};