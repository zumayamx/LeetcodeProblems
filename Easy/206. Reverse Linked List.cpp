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
    ListNode* reverseList(ListNode* head) {
        
        // One pointer to points to nullptr
        ListNode* prev = nullptr;
        ListNode* curr = head;
    
        // While curr doesn't poits to nullptr (end of the list)
        while (curr)
        {
            // Save the reference to next node
            ListNode* nextTmp = curr->next;
            
            // Reverse the current node's pointer
            curr->next = prev;
            
            // Move the prev and curr pointers forward
            prev = curr;
            curr = nextTmp;
        }

        // Return the new head of the reverse list
        return prev;
    }
};
