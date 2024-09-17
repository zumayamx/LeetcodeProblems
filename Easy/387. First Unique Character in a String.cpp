class Solution {
public:
    int firstUniqChar(string s) {
        
        // Define a map to store the occurrences of each character in the string s
        unordered_map<char, int> ocurr;
        
        // Fill the map with the occurrences of each character
        for (char e : s)
        {
            ocurr[e]++;
        }
        
        // Iterate over the string, checking the number of
        // occurrences of each character
        for (int i = 0; i < s.size(); i++)
        {
            // If the occurrences equal 1, return the index of that character in the string s
            // This guarantees that it is the first non-repeating character, since the map was filled
            // from left to right, so the elements are checked in the same order they appear in the
            // string
            if (ocurr[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
