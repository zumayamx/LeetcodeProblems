class Solution {
public:
    int lengthOfLastWord(string s) {

        int p = s.length() - 1;

        // First, skip all trailing whitespace characters
        // until a non-whitespace character is found.
        while (p >= 0 && s[p] == ' ')
        {
            p--;
        }

        // Then, count the length of the last word
        // by iterating from the end of the string
        // towards the start until another whitespace is encountered.
        int len = 0;
        while (p >= 0 && s[p] != ' ')
        {
            len++;
            p--;
        }

        return len;
    }
};
