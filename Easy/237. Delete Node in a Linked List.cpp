class Solution {
public:
    void deleteNode(ListNode* node) {
	// Copy the value of the next node in the current node
	// then update the next pointer of the current node to
	// points to next of next node
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
