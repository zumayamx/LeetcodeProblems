/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: If the tree is empty (root is null), its depth is 0 or if we reached
	// the end of a "branch"
        if (!root) return 0;

        // Recursive case:
        // Calculate the depth of the left and right subtrees using recursion.
        // Add 1 to account for the current root node.
        // Return the maximum of the two depths.
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
