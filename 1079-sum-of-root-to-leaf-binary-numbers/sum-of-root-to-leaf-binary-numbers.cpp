class Solution {
public:
    int solve(TreeNode* root, int curr) {
        if (!root) return 0;

        // Update the binary number
        curr = curr * 2 + root->val;

        // If leaf node, return the formed number
        if (!root->left && !root->right)
            return curr;

        // Otherwise, go deeper
        return solve(root->left, curr) + solve(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};