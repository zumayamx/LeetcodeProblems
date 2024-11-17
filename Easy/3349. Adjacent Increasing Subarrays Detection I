class Solution {
public:
    /**
     * Function to determine if a subarray is in strictly increasing order.
     * @param nums: Reference to a vector of integers representing the number series.
     * @param index: Starting index of the subarray to check.
     * @param k: Length of the subarray to evaluate.
     * @return True if the subarray is in strictly increasing order, false otherwise.
     */
    bool isIncreasingFromIndex(vector<int>& nums, int index, int k)
    {
        // Iterate through the subarray starting at 'index' and spanning 'k' elements.
        // Check if every element is strictly less than the next element.
        for (int i = index; i < index + k - 1; i++)
        {
            if (nums[i] >= nums[i + 1]) return false; // Return false if order is violated.
        }
        return true; // Return true if all elements are in increasing order.
    }

    /**
     * Function to check if there exist two adjacent subarrays of length 'k' that are both 
     * in strictly increasing order.
     * @param nums: Reference to a vector of integers representing the number series.
     * @param k: Length of each subarray to evaluate.
     * @return True if such adjacent subarrays exist, false otherwise.
     */
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        // Iterate over the vector using a sliding window approach.
        // Ensure that the loop avoids invalid positions by stopping at 
        // 'nums.size() - 2 * k', as we need two adjacent subarrays of length 'k'.
        for (int i = 0; i <= nums.size() - 2 * k; i++)
        {
            // Check if the first subarray (starting at 'i') is in increasing order.
            // Check if the second subarray (starting at 'i + k') is in increasing order.
            // If both conditions are met, return true.
            if (isIncreasingFromIndex(nums, i, k) && isIncreasingFromIndex(nums, i + k, k))
            {
                return true;
            }
        }

        // Return false if no such adjacent subarrays are found.
        return false;
    }
};
