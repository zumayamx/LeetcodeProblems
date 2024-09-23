class Solution {
public:
    int myAtoi(string s) {
        
        // Initialize the base number as 0
        int num = 0;
        
        // Initialize sign as positive (1)
        int sign = 1;
        
        // Skip leading whitespace characters
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;

        // Check if there's a sign indicator (+ or -)
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1; // Set sign accordingly
            i++;
        }
        
        // Iterate over the string to convert the characters to an integer
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';  // Convert current character to its numeric value
            
            // Check if adding the next digit would cause an overflow
            // INT_MAX is 2147483647, so we check if num*10 + digit would exceed this
            if (num > (INT_MAX - digit) / 10) {
                // If overflow happens, return INT_MAX for positive numbers and INT_MIN for negative
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            // Accumulate the digit into num
            num = num * 10 + digit;
            i++;
        }
        
        // Return the final result after applying the sign
        return num * sign;
    }
};
