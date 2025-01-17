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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Define a prehead node to simplify the logic for merging the lists.
        // This acts as a dummy node to provide a starting point for the new list.
        ListNode prehead(-1);
        ListNode* prev = &prehead;
        
        // Traverse both lists until one of them is fully processed.
        // Compare the current nodes of l1 and l2 to decide which node
        // to add to the merged list.
        while (l1 != nullptr && l2 != nullptr) {
            // If the value of the current node in l1 is less than or equal
            // to the value of the current node in l2:
            if (l1->val <= l2->val) {
                // Connect the l1 node to the merged list.
                prev->next = l1;
                
                // Move the l1 pointer to the next node as the current node
                // has been added to the merged list.
                l1 = l1->next;
            } else {
                // Otherwise, the value of the l2 node is less than l1's value.
                // Connect the l2 node to the merged list.
                prev->next = l2;
                
                // Move the l2 pointer to the next node as the current node
                // has been added to the merged list.
                l2 = l2->next;
            }
            
            // Move the prev pointer forward to continue building the merged list.
            prev = prev->next;
        }
        
        // At this point, one of the lists has been fully processed.
        // If l1 is not null, it means all remaining nodes in l1 are greater
        // than the nodes already added to the merged list. Since l1 is already
        // sorted, simply connect it to the merged list. The same logic applies
        // if l2 is not null.
        prev->next = l1 == nullptr ? l2 : l1;
        
        // Return the head of the merged list, which is the next node after prehead.
        return prehead.next;
    }
};
