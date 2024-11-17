/*
 * This solution can be improved by using the two-pointer approach.
 * Currently, it is a brute-force solution.
 */
int removeElement(vector<int>& nums, int val) {
    // Iterate over the vector and check if the value
    // is equal to val. If it is, remove the element
    // and decrement i to point to the current element
    // because the length of nums has been reduced by one
    // during the erase operation.
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            nums.erase(nums.begin() + i);
            i--;
        }
    }

    // Return the final length of the nums vector.
    return nums.size();
}
