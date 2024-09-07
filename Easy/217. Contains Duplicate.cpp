class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> ocurr;
        
        for (int e : nums)
        {
            if (ocurr[e] >= 1)
            {
                return true;
            }
            ocurr[e]++;
        }
        return false;
    }
};