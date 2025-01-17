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
        // Use an unordered_set to track visited nodes.
        // This helps detect cycles by checking if a node
        // has already been visited as we traverse the list.
        unordered_set<ListNode *> visitedNodes;

        // Initialize a pointer to traverse the list.
        // Start with the head of the list.
        ListNode* curr = head;

        // Traverse the list until we either reach the end (nullptr)
        // or detect a cycle.
        while (curr) {
            // If the current node is already in the set, it means
            // we have encountered a cycle. Return true.
            if (visitedNodes.find(curr) != visitedNodes.end()) {
                return true;
            }

            // Otherwise, add the current node to the set of visited nodes.
            visitedNodes.insert(curr);

            // Move to the next node in the list.
            curr = curr->next;
        }

        // If we reach the end of the list (nullptr), no cycle is present.
        return false;
    }
};
