class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxWater=0;

        //moving two pointer towards each other
        while(left<right){
            //calculating area between lines left and right
            int width=right-left;
            int minHeight=min(height[left],height[right]);
            int area=width*minHeight;

            //updting maximum water found so far
            maxWater=max(maxWater,area);

            //moving the pointer to the shorter line inward
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};