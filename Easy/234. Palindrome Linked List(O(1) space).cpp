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
        // Check if the input list is empty
        if (!head) return false;

        // Find the end of the first half of the list
        ListNode* firstHalfEnd = endOfFirstHalf(head);

        // Reverse the second half of the list starting after the midpoint
        ListNode* headOfReverseList = reverseList(firstHalfEnd->next);

        // Initialize the result as true (assume the list is a palindrome)
        bool result = true;

        // Compare the first half of the list with the reversed second half
        ListNode* p2 = headOfReverseList; // Pointer to traverse the reversed list
        while (p2) {
            // If values differ, the list is not a palindrome
            if (head->val != p2->val) {
                result = false;
                break;
            }
            // Move both pointers forward
            p2 = p2->next;
            head = head->next;
        }

        // Restore the original list structure by reversing the second half back
        firstHalfEnd->next = reverseList(headOfReverseList);

        return result;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        // Use a two-pointer approach to find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Move the slow pointer one step and the fast pointer two steps
        // This ensures that the slow pointer stops at the midpoint when
        // the fast pointer reaches the end of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return a pointer to the midpoint of the list
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        // Use the same approach as the "reverse list" problem.
        // Notice the initialization of prev = nullptr. This is essential because
        // we need the nullptr reference to determine when the right-middle of the
        // list has been fully processed. Additionally, it allows us to restore
        // the original list structure later.
        ListNode* prev = nullptr; // Initially, prev points to nullptr
        ListNode* curr = head;    // Start with the head of the list

        while (curr) {
            // Temporarily store the next node
            ListNode* nextTmp = curr->next;

            // Reverse the current node's pointer
            curr->next = prev;

            // Move the prev and curr pointers forward
            prev = curr;
            curr = nextTmp;
        }

        // Return the new head of the reversed list
        return prev;
    }
};
