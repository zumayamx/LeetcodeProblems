class Solution {
public:
    int reverse(int number32) 
    {
        int reverse_number = 0;
        
        // Use number32 since we divide number32 by tens
        while (number32)
        {
            // Check if the reverse_number exceeds the limits of a 32-bit integer
            if ((reverse_number < INT_MIN / 10) || (reverse_number > INT_MAX / 10))
            {
                return 0;
            }
            
            // Update the reverse_number, first multiply by 10 to "left shift" the digits
            // and create space for the next "remainder digit" obtained by the operation number32 % 10
            reverse_number = reverse_number * 10 + (number32 % 10);
            
            // Update number32, divide by 10 to reduce it by one digit,
            // so in the next iteration, the remainder will reflect the new rightmost digit
            number32 = number32 / 10;
        }
        
        return reverse_number;
    }
};
