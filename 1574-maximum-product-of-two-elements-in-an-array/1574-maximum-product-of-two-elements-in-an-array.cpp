class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0; // store the two largest numbers

        // Loop through all elements to find the two largest
        for(int num : nums) {
            if(num > max1) {
                // current number is the largest so far
                max2 = max1; // shift previous max to second largest
                max1 = num;  // update max1
            } else if(num > max2) {
                // current number is second largest
                max2 = num;
            }
        }

        // Dry Run Example: nums = [3,4,5,2]
        // Iteration 1: num=3 -> max1=3, max2=0
        // Iteration 2: num=4 -> max1=4, max2=3
        // Iteration 3: num=5 -> max1=5, max2=4
        // Iteration 4: num=2 -> max1=5, max2=4
        // Result: (5-1)*(4-1) = 4*3 = 12

        return (max1-1)*(max2-1);
    }
};
