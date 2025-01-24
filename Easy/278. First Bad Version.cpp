// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Use a binary search approach

        // Define the left boundary as 1, since
        // version numbering starts from 1
        int left = 1;
        
        // Define the right boundary as n
        int right = n;
        
        // Continue the search while the left pointer is less than the right pointer
        while (left < right)
        {
            // Set the pivot to the middle of the search range.
            // This notation prevents integer overflow
            int pivot = left + (right - left) / 2;
            
            // If the current pivot is a bad version, it means
            // the first bad version might be before it.
            // Therefore, adjust the search range to explore earlier versions.
            if (isBadVersion(pivot))
            {
                right = pivot;
            }
            // Otherwise, the bad version must be further ahead,
            // so move the left boundary forward to search in the later versions.
            else {
                left = pivot + 1;
            }
        }
        
        // At the end, both left and right pointers converge to the first bad version
        return right;
    }
};
