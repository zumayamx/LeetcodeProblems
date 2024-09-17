class Solution {
public:
    void reverseString(vector<char>& s) {
        // Use the two poinert approach to iterate over the string
        
        // One pointer to move from left-rigth
        int left = 0;
        
        // Another to move rigth-left
        int rigth = s.size() - 1;
        
        // Condition left < rigth to avoid over-swap
        while (left < rigth)
        {
            // Swap the elements
            swap(s[left], s[rigth]);
            
            // Move the pointers to next position
            left++;
            rigth--;
        }
    }
};
