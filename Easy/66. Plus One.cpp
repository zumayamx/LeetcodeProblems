class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Save the lenght of the number
        int l = digits.size();
        
        for (int i = l - 1; i >= 0; i--)
        {
            // If we are in the last element from left to rigth, plus one, like a normal sum, only once
            // to "start" the sum
            if ( i == l - 1)
            {
                digits[i]++;
            }
                
            // If that first sum results in ten or whatever element in next iterations, convert that               // element in 0 and pass the carry
            if ( digits[i] == 10)
            {
                digits[i] = 0;

                // Here pass the carry to next element from rigth to left, only if it doesn't the
                // last element from left to rigth
                if (i != 0)
                {
                    // Here access to next digit and sum the carry
                    digits[i - 1]++;
                }
                
                // If that element is the last from rigth to left 
                else
                {
                    // Add the digit 0 to represent a new step of number
                    digits.push_back(0);
                    // Set the last element to 1, cause only in change in step
                    digits[i] = 1;
                }
            }
        }
    return digits;
    }
};