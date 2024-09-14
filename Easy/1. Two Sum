class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // Define a map to save each value with it index
        unordered_map<int, int> index;
        vector<int> result (2, 0);
        
        // Fill the map with each element of the vector nums like key and it index like value
        for (int i = 0; i < nums.size(); i++)
        {
            index[nums[i]] = i;
        }
        
        // Now iterate over the vector and define a value to reach target depends the actual value
        for (int j = 0; j < nums.size(); j++)
        {
            int value = target - nums[j];
            
            // If the value to reach the target is present in the map return it index
            // and isn't the actual element
            if (index.find(value) != index.end() && index[value] != j)
            {
                // If this is correct, just add it the actual index of two elements to result vector
                result[0] = j;
                result[1] = index[value];
                break;
            }
        }
     return result;
    }
};
