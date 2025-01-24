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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Define the output vector to store the level order traversal result
        vector<vector<int>> levels;

        // If the root is nullptr, return an empty vector
        if (!root) return levels;

        // Use a queue to store nodes level by level
        queue<TreeNode*> q;
        q.push(root);

        // Initially, we start at level 0
        // Implicitly, we have ONE level at the beginning
        int level = 0;

        // While there are nodes left to explore
        while (!q.empty())
        {
            // Add a new vector to store the current level nodes
            levels.push_back({});

            // Get the number of nodes at the current level
            int total_nodes = q.size();

            // For each node at this level, we need to push its child nodes into the queue
            // We explore the entire tree from top to bottom, similar to water flowing down,
            // reaching all levels simultaneously and adding the child nodes of the current level
            // for processing in the next iteration
            for (int i = 0; i < total_nodes; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                // Add the value of the current node to the current level
                levels[level].push_back(curr->val);

                // If the left or right children exist, push them to the queue
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            // Move to the next level
            level++;
        }
        return levels;
    }
};
