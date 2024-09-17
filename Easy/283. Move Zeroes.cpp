class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // Define the left pointer
        int l = 0;
        
        // Then iterate over the vector, define the r pointer at the same time
        for (int r = 0; r < nums.size(); r++)
        {
            // If the actual element it's not equals to 0, then swap with the element in the left
            // pointer
            if ( nums[r] != 0)
            {
                // Swap the elements
                swap(nums[r], nums[l]);
                
                // Move the left pointer to next element
                l++;
            }
        }
    }
}
