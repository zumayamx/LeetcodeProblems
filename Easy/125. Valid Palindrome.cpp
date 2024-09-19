class Solution {
public:
    bool isPalindrome(string s) 
    {
        // Iterate over the string and erase any character that isn't alphanumeric
        for (int i = 0; i < s.size(); i++)
        {
            if (!isalnum(s[i]))
            {
                s.erase(i, 1); // Erase the non-alphanumeric character
                i--; // Adjust the index to account for the removed character
            }
        }
        
        // Use the two-pointer approach to compare characters from both ends
        int left = 0;
        int right = s.size() - 1;
        
        // Loop until the two pointers meet
        while (right > left)
        {
            // Convert both characters to lowercase and compare them
           if (tolower(s[right]) != tolower(s[left])) 
           {
               return false; // If characters don't match, it's not a palindrome
           }
            
            // Move the pointers towards the center
            left++;
            right--;
        }
        
        // If all characters match, return true
        return true;
    }
};
