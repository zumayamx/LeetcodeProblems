class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // Create a dummy node to simplify edge cases, such as deleting the head node.
        // Example:
        // Original List: 1 -> 2 -> 3 -> 4 -> 5, n = 5
        // After adding dummy node: 0(dummy) -> 1 -> 2 -> 3 -> 4 -> 5
        // 
        // In this scenario:
        // - The 'two' pointer moves n steps forward (to the node with value 5).
        // - The while loop doesn't execute because two->next == nullptr.
        // - The 'one' pointer's next points to the target node (head), and the node is deleted.
        // - However, the 'head' pointer still points to the deleted node, which is invalid.
        // - The dummy->next correctly points to the new head of the list.

        ListNode* dummy = new ListNode(0, head);
        ListNode* one = dummy;
        ListNode* two = dummy;
        
        // Move the 'two' pointer n steps forward
        for (int i = 0; i < n; i++) {
            two = two->next;
        }
        
        // Move both 'one' and 'two' pointers until 'two' reaches the end of the list.
        // At this point, 'one->next' points to the target node to be deleted.
        while (two->next != nullptr) {
            one = one->next;
            two = two->next;
        }
        
        // Delete the target node
        ListNode* toDelete = one->next;
        one->next = one->next->next; // Re-link the list to skip the deleted node
        delete toDelete; // Free the memory of the target node

        // Save the updated head of the list
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node's memory
        
        return newHead; // Return the new head of the list
    }
};
