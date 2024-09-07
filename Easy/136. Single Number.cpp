class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ocurr;
        
        for (int e : nums)
        {
           ocurr[e]++;
        }
        
        for (auto o: ocurr)
        {
            if(o.second == 1) return o.first;
        }
        
        return -1;
    }
};