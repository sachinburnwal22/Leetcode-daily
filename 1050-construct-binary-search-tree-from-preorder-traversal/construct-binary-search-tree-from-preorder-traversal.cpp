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
    TreeNode* insert(TreeNode* root, int v){
        if(root == NULL){
            return new TreeNode(v);
        }

        if(root->val < v){
            root->right = insert(root->right, v);
        }else{
            root->left = insert(root->left, v);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        int n = preorder.size();
        for(int i=0; i<n; i++){
            root = insert(root, preorder[i]);
        }
        return root;
    }
};