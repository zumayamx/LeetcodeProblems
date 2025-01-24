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
private:
    stack<TreeNode*> stack, lower_l, upper_l;
public:
    // Function to update the limits of the current node
    void update(TreeNode* root, TreeNode* low, TreeNode* high)
    {
        stack.push(root);
        lower_l.push(low);
        upper_l.push(high);
    }
    bool isValidBST(TreeNode* root) {
        // Initial conditions the lower and upper limit of
        // the root node is nullptr
        TreeNode* lower = nullptr;
        TreeNode* upper = nullptr;

        // So, put in the stack's the correspondent limits
        // to a current node
        update(root, lower, upper);

        // While we have not visited
        // al nodes...
        while(!stack.empty())
        {
            // Get the current node
            root = stack.top();
            stack.pop();

            // Get the lower limit
            lower = lower_l.top();
            lower_l.pop();

            // Get the upper limit
            upper = upper_l.top();
            upper_l.pop();

            // If the root node is null, continue
            // that means we have reached the end of
            // a branch, so we need to pop it a new node
            // if exists
            if (!root) continue;

            // Get the current node
            TreeNode* curr_node = root;

            // If we have lower limit that means
            // we are in a right node, so the value must be greater
            // than the value of the curr node
            if (lower && curr_node->val <= lower->val) return false;

            // If we have upper limit that means
            // we are in a left node, so the value must be less
            // than the value of the curr node
            if (upper && curr_node->val >= upper->val) return false;

            // Update the limits fo each node right and left
            // of current node

            // For the left node it's low limit must be nullptr
            // cause we would have as far as -2^31 values, but
            // it's upper limit must be his "father" cause all nodes
            // to left of a root must be have a values less than "father"
            // value, the same ocurrs with right side.
            update(curr_node->left, lower, curr_node);
            update(curr_node->right, curr_node, upper);
        }

        return true;
    }
};

