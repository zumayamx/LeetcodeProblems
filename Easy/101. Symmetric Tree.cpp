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
    bool isSymmetric(TreeNode* root) {
        // If the root is null, the tree is considered symmetric.
        if (!root) return true;

        // Use a queue to process the nodes level by level.
        queue<TreeNode*> q;

        // Push the left and right child nodes of the root into the queue.
        // (Order of insertion is crucial to ensure proper mirroring check)
        q.push(root->left);
        q.push(root->right);

        // Process nodes in pairs until the queue is empty.
        while (!q.empty()) {
            // Retrieve and remove the first two nodes from the queue.
            TreeNode* n1 = q.front();
            q.pop();

            TreeNode* n2 = q.front();
            q.pop();

            // If both nodes are null, they are symmetric; continue processing.
            if (!n1 && !n2) continue;

            // If only one of the nodes is null, the tree is not symmetric.
            if (!n1 || !n2) return false;

            // If the values of the nodes are different, the tree is not symmetric.
            if (n1->val != n2->val) return false;

            // Add the corresponding child nodes to the queue for further comparison:
            // - The left child of the left subtree with the right child of the right subtree.
            q.push(n1->left);
            q.push(n2->right);

            // - The right child of the left subtree with the left child of the right subtree.
            q.push(n1->right);
            q.push(n2->left);
        }

        // If all pairs of nodes match symmetrically, the tree is symmetric.
        return true;
    }
};
