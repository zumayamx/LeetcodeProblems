class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        // Define the steps of the ant from the boundary
        // and the number of times that it returns to
        // the boundary
        int steps = 0;
        int boundary_return = 0;

        // Iterate over the steps
        for (int i = 0; i < nums.size(); i++)
        {
            // If the current number is not 0, then
            // belongs to + or - numbers
            if (nums[i] != 0)
            {
                // Sum to steps variale
                steps += nums[i];

                // Check if it's 0, so the ant return to
                // the boundary
                if (steps == 0) boundary_return++;
            }
            
        }
        return boundary_return;
    }
};
