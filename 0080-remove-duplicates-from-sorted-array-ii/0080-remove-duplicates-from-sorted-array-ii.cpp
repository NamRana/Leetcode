class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0; // j = position to place next valid element

        for (int i = 0; i < nums.size(); i++) {
            // if j < 2, we can always place first two elements
            // or if nums[i] != nums[j-2], it means nums[i] hasn't occurred more than twice
            if (j < 2 || nums[i] != nums[j - 2]) {
                nums[j] = nums[i]; // place nums[i] at position j
                j++;               // move j forward
            }
        }

        return j; // new length of array after removing extra duplicates
    }
};
