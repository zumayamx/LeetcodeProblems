class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Define the lengths of the two strings
        int n1 = word1.length();
        int n2 = word2.length();

        // Use two pointers:
        // 'i' for tracking characters in word1 and 'j' for word2
        int i = 0, j = 0;

        // Initialize the result string
        string result = "";

        // Continue looping as long as either word still has characters left
        while (i < n1 || j < n2)
        {
            // If 'i' is within bounds for word1, append the current character  from word1
            if (i < n1)
            {
                result += word1[i];
                i++;
            }

            // If 'j' is within bounds for word2, append the current character from word2
            if (j < n2)
            {
                result += word2[j];
                j++;
            }
        }

        // Return the merged result
        return result;
    } 
};
