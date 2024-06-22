class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_s = 0;
        vector<int> count(256);
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            count[s[i]]++;
            while (count[s[i]] > 1)
            {
                count[s[j++]]--;
            }
            max_s = max(max_s, i - j + 1);
        }
    return max_s;
    }
};