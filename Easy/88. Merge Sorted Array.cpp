class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Iterate over the len of result nums1
        for (int i = 0; i < m + n; i++)
        {
            // If the we have reached the number of elements that
            // bolong to nums1 originally, we can set the elements of
            // nums2
            if (i >= m)
            {
                nums1[i] = nums2[i - m];
            }
        }

        // Finally we sort the nums1 vector
        sort(nums1.begin(), nums1.end());

        return;
    }
};
