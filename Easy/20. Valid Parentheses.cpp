class Solution {
public:
    bool isValid(string s) {
        // First, we need a map to match each possible
        // character in the string with its
        // corresponding closing character.
        unordered_map<char, char> match_ch;
        match_ch['('] = ')';
        match_ch['{'] = '}';
        match_ch['['] = ']';

        // We use a stack to store and match
        // each character one by one.
        stack<char> match;

        // Iterate over the string to process
        // each character from left to right.
        for (char c : s) {

            // If the character is a key in the map,
            // it means it is an opening character, so we push it
            // onto the stack. This process is repeated
            // each time an opening character appears in the string.
            if (match_ch.find(c) != match_ch.end()) {
                match.push(c);
            } 
            
            // If the character is not a key in the map,
            // it means it is a closing character. We need to match it
            // with the last inserted character from the stack to ensure
            // the order of opening and closing characters is correct.
            else {

                // If the stack is empty but there are still characters
                // to process, return false because there is no opening
                // character to match with the current closing character.
                if (match.empty()) return false;

                // Get the last inserted character.
                char open = match.top();

                // Since it's guaranteed that this is a closing character,
                // we always pop the top element from the stack regardless
                // of whether it matches or not.
                match.pop();

                // If the value (corresponding closing character) of the last
                // element in the stack does not match the current character,
                // return false because the order is incorrect.
                if (match_ch[open] != c) return false;
            }
        }

        // If the stack is empty, the string is valid.
        // If the stack still contains elements, the string is invalid
        // because these elements do not have corresponding closing characters.
        return match.empty();
    }
};
