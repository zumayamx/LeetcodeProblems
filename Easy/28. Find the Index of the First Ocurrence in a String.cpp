class Solution {
public:
    // Fuction to get the hash value of a string, using roling hash
    // RADIX is the base number to multiply each value of string
    // MOD is used to avoid overflow
    int hash_value(string string, int m, int RADIX, int MOD) {
        int ans = 0;
        long factor = 1;

        // Iterate over the string and accumulate has value in ans variable
        for (int i = m - 1; i >= 0; i--) {
            ans = (ans + (string[i] - 'a') * factor) % MOD;

            // Use iterative form to obtain factor value,
            // now using pow()
            factor = (factor * RADIX) % MOD;
        }

        return ans;
    }

    // Fucton to find needle in haystack
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();

        if (n < m)
            return -1;

        int RADIX = 26;
        int MOD = 1000000033;
        long MAX_WEIGHT = 1;

        // Get the max posible factor to multiply each value of needle
        // is useful to use in upcoming operations
        for (int i = 0; i < m; i++)
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

        // Get the hash value of needle to compare it against each hash calculated
        long hash_needle = hash_value(needle, m, RADIX, MOD), actual_hash = 0;

        for (int window_start = 0; window_start <= n - m; window_start++) {
            if (window_start == 0) {
                // Get the first sub-string hash
                actual_hash = hash_value(haystack, m, RADIX, MOD);
            } else {
                // Move the window one position to rigth and calculate
                // the new hash value width roling

                // Actual hash is equals to actual hash dot RADIX to move the factor
                // one position to left (pow()) minus the most-left character value
                // cause is out of the window plus the most-rigth character value
                // cause is the new character in the window
                actual_hash =
                    ((actual_hash * RADIX) % MOD -
                     ((int)(haystack[window_start - 1] - 'a') * MAX_WEIGHT) %
                         MOD +
                     (int)(haystack[window_start + m - 1] - 'a') + MOD) %
                    MOD;
            }

            // If the hash of needle is equals to the actual hash
            // compare it character by character
            if (hash_needle == actual_hash) {
                for (int i = 0; i < m; i++) {
                    if (needle[i] != haystack[i + window_start]) {
                        break;
                    }

                    // If the all characters are equals, that means
                    // we find the sub-string (needle) so return window
                    // start
                    if (i == m - 1) {
                        return window_start;
                    }
                }
            }
        }

        // If there are not coincidences return -1
        return -1;
    }
};
