class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Implementing a three-pointer approach to merge arrays efficiently
        
        // Create a copy of the first m elements from nums1
        vector<int> nums1_c(nums1.begin(), nums1.begin() + m);
        
        // p1 points to the current index in the copied nums1 vector
        int p1 = 0;
        
        // p2 points to the current index in nums2
        int p2 = 0;

        // Iterate through the entire merged array (nums1)
        for (int p = 0; p < m + n; p++)
        {
            // If all elements from nums2 have been processed,
            // or if there are remaining elements in nums1_c that are smaller
            // than the current element in nums2, copy the element from nums1_c.
            if (p2 >= n || (p1 < m && nums1_c[p1] < nums2[p2])) {
                nums1[p] = nums1_c[p1++];
            }
            // Otherwise, copy the element from nums2 as it is smaller
            else {
                nums1[p] = nums2[p2++];
            }
        }
    }
};

