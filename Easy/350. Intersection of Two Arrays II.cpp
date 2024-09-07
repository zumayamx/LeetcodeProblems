class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ocurr;
        vector<int> result;
        
        // Fill all the ocurrences of each element in the first vector
        for (int i = 0; i < nums1.size(); i++)
        {
            ocurr[nums1[i]]++;
        }
        
        // Compare if each element in second vector is in first vector
        for (int i = 0; i < nums2.size(); i++)
        {
            // Get and store the element of second vector
            int element = nums2[i];
            
            // Look if the element of the second vector is present in first vector
            if (ocurr.find(element) != ocurr.end())
            {
                // Add the element to result vector, because it is present in both vectors
                result.push_back(element);
                
               // Subtract the occurrences of that element in the first vector since its corresponding                // element has been found in the second vector, indicating that the element has already                // been "used"
                ocurr[element]--;
                
                // If the ocurr of element it´s equals to 0 in first vector, erase it because all                       // ocurrences of that element have been used
                if (ocurr[element] == 0)
                {
                    ocurr.erase(element);
                }
            }
        }
        
        return result;
    }
};