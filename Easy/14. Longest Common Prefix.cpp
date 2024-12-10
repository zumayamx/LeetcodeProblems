class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If the list of strings is empty return ""
        if (strs.empty()) return "";

        // Select the first string in the list as
        // the candidate to prefix, then when compare it
        // against other strings in the list, we reduce this
        // string as we need it
        string candidate_prefix = strs[0];
        
        for (int i = 1; i < (int)strs.size(); i++) {
            int j = 0;
            // Compare each character of the current string against to candidate prefix,
            // define j as a pointer to access to each character in the candidate prefix,
            // then we need that j doesn't be major that the len of the current string
            // to avoid out-of-range error (that means, we found a new prefix candidate), 
            // finally the character in the candidate prefix must be equal to the character 
            // in the current string
            while (j < (int)candidate_prefix.size() && j < (int)strs[i].size() && candidate_prefix[j] == strs[i][j]) {
                j++;
            }
            // Cut the candidate prefix to pos 0 to j
            candidate_prefix = candidate_prefix.substr(0, j);
            
            // If there aren't a prefix return ""
            if (candidate_prefix.empty()) return "";
        }
        
        return candidate_prefix;
    }
};
