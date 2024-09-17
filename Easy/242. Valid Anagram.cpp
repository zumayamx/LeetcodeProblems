class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (t.size() != s.size()) return false;
        
        // Define an unordered map to store the possible letters and
        // their respective number of occurrences
        unordered_map<char, int> alphabet;
        
        // Fill the map with the occurrences of each character in the string s
        for (char e : s)
        {
            alphabet[e]++;
        }
        
        // Iterate over the string t, matching each character with the corresponding one in the string s
        // and decrement the count of the letter in the map
        for (int i = 0; i < t.size(); i++)
        {
            // If the letter in the second string isn't present in the map or if the letter in t
            // is used more times than allowed, return false
            if (alphabet.find(t[i]) == alphabet.end() || alphabet[t[i]] == 0)
            {
                return false;
            }
            // Otherwise, decrement the count of the letter by one
            else
            {
                alphabet[t[i]]--;
            }
        }
        
        // Check if there are no remaining letters, since an anagram must use
        // each letter exactly once
        for (int i = 0; i < t.size(); i++)
        {
            if (alphabet[t[i]] > 0) return false;
        }
        
        return true;
    }
};
