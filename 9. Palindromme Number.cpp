class Solution {
public:
    bool isPalindrome(int x) {

        // Check edge cases where the number cannot be a palindrome:
        // 1. If the number is negative, it cannot be a palindrome.
        // 2. If the number ends with 0 and is not 0 itself, it cannot be a palindrome.
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        // Variable to store the reversed half of the number.
        int revertedNumber = 0;

        // Reverse the digits of the number until the original number is less than or equal to the reversed half.
        while (x > revertedNumber)
        {
            // Extract the last digit by taking the remainder when divided by 10,
            // then add it to the reversed number, shifting the digits to the left.
            revertedNumber = revertedNumber * 10 + x % 10;

            // Remove the last digit from the original number by performing integer division by 10.
            x /= 10;
        }

        // Check if the number is a palindrome:
        // 1. For even-length numbers, the reversed half (revertedNumber) should equal the remaining original number (x).
        // 2. For odd-length numbers, remove the middle digit from the reversed half (revertedNumber / 10) and compare with the remaining original number (x).
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
