class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0, currentSum = 0;
        vector<int> count(100001, 0);
        
        for (int i = 0, j = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            currentSum += nums[i];
            
            while (count[nums[i]] > 1) {
                count[nums[j]]--;
                currentSum -= nums[j];
                j++;
            }
            
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};