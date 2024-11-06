#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        // Create a map to associate Roman numeral characters and special combinations with their integer values
        std::unordered_map<std::string, int> romanInt;
        
        // Map all individual Roman numerals and special cases (like "IV" or "IX") to their integer values
        romanInt["I"] = 1;
        romanInt["IV"] = 4;
        romanInt["V"] = 5;
        romanInt["IX"] = 9;
        romanInt["X"] = 10;
        romanInt["XL"] = 40;
        romanInt["L"] = 50;
        romanInt["XC"] = 90;
        romanInt["C"] = 100;
        romanInt["CD"] = 400;
        romanInt["D"] = 500;
        romanInt["CM"] = 900;
        romanInt["M"] = 1000;

        // Initialize a variable to store the cumulative integer value of the Roman numeral string
        int sum = 0;
        
        // Iterate through the string of Roman numerals
        for (int i = 0; i < s.size(); ) {
            // Check if a two-character substring (like "IV" or "IX") exists in the map
            // This also ensures we don’t go out of bounds on the last character
            if (i <= s.size() - 2 && romanInt.find(s.substr(i, 2)) != romanInt.end()) {
                sum += romanInt[s.substr(i, 2)]; // Add the value of the two-character Roman numeral
                i += 2; // Move forward by two characters since we processed a two-character numeral
            } else {
                // Otherwise, add the value of the single character
                sum += romanInt[s.substr(i, 1)];
                i++; // Move forward by one character
            }
        }

        // Return the total sum, which represents the integer value of the Roman numeral string
        return sum;
    }
};
