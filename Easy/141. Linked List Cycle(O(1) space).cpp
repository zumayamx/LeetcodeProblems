/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Use the two-pointer approach (Floyd's Cycle Detection Algorithm).
        // If the list is empty, it cannot have a cycle, so return false.
        if (!head) return false;

        // Initialize two pointers:
        // - The slow pointer moves one step at a time.
        // - The fast pointer moves two steps at a time.
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list while the fast pointer and its next node are not null.
        // This ensures we do not access invalid memory in case of a non-cyclic list.
        while (fast->next && fast->next->next) {
            // Move the slow pointer one step forward.
            slow = slow->next;

            // Move the fast pointer two steps forward.
            fast = fast->next->next;

            // If the fast pointer catches up with the slow pointer,
            // a cycle exists in the list.
            if (slow == fast) {
                return true;
            }
        }

        // If the fast pointer reaches the end of the list,
        // there is no cycle.
        return false;
    }
};
