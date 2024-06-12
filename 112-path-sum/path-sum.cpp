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
    bool hasPathSum(TreeNode* root, int targetSum) {
                // If the root is null, there's no path, so return false
        if (root == nullptr) {
            return false;
        }
        
        // Check if we're at a leaf node and if the path sum equals targetSum
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        // Recur down the left and right subtrees, subtracting the current node's value from targetSum
        int newTargetSum = targetSum - root->val;
        return hasPathSum(root->left, newTargetSum) || hasPathSum(root->right, newTargetSum);
    
    }
};