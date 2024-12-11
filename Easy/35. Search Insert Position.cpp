class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // We use a binary search approach.
        int left = 0;
        int right = (int)nums.size() - 1;
        int index_pivot = 0;

        while (left <= right)
        {
            // Define the index pivot as the middle
            // of the array. Use this notation
            // to avoid an INT_MAX overflow.
            index_pivot = left + (right - left) / 2;

            // If the number at the index pivot
            // is equal to our target, simply return the index.
            if (nums[index_pivot] == target) return index_pivot;

            // If the target is less than the current number
            // at the pivot index, update the right pointer
            // to index_pivot - 1 to focus on the left part.
            if (target < nums[index_pivot])
            {
                right = index_pivot - 1;
            }

            // Otherwise, if the target is greater than the current number,
            // update the left pointer to index_pivot + 1 to focus
            // on the right part.
            else
            {
                left = index_pivot + 1;
            }
        }

        // Return the left pointer. If the target is not in the array,
        // the left pointer will indicate the correct index where
        // the target should be inserted.
        return left;
    }
};
