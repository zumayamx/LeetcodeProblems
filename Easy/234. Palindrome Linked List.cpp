/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Use a two pointer aproach and copy the list to an array

        if (!head) return false;

        // Define the curr pointer to points to head
        ListNode* curr = head;

        // Define the vector to store all values of the list
        vector<int> list_array;

        // While we don't reach the end of the list
        // copy the values
        while (curr)
        {
            list_array.push_back(curr->val);

            // Move the curr pointer to next node
            curr = curr->next;
        }

        // Define the two pointers
        // one goes up and the other goes down
        int i = 0;
        int j = list_array.size() - 1;

        // Check if character by character
        // to find a palindrome
        while (i < j)
        {
            if (list_array[i] != list_array[j]) 
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};
