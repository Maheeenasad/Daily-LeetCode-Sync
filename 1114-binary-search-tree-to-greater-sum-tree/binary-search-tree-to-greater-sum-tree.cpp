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
 int sum = 0; // Initialize sum
    TreeNode* bstToGst(TreeNode* root) {
         if (root != nullptr) {
            bstToGst(root->right); // Traverse right subtree first
            sum += root->val; // Update sum with current node's value
            root->val = sum; // Update current node's value with sum
            bstToGst(root->left); // Traverse left subtree
        }
        return root; 
    }
};