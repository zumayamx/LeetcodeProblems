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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Use a recursive approach. In each step, we need to
        // define a "root". Initially, the left boundary is 0
        // and the right boundary is the size of the nums vector minus one.
       return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right)
    {
        // If the left pointer exceeds the right pointer,
        // it means there are no remaining elements to process,
        // similar to a binary search algorithm.
        if (left > right) return nullptr;

        // Determine the middle index
        int root_index = (left + right) / 2;

        // Create a new node with the middle element
        TreeNode* root = new TreeNode(nums[root_index]);

        // Recursively build the left subtree.
        // The left boundary remains the same, but the right boundary
        // is updated to root_index - 1.
        root->left = helper(nums, left, root_index - 1);

        // Recursively build the right subtree.
        // The left boundary is updated to root_index + 1,
        // while the right boundary remains the same.
        root->right = helper(nums, root_index + 1, right);

        // After all recursive calls, return the root node,
        // which ultimately points to the true root of the BST.
        return root;
    }
};
