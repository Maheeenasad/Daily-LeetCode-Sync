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
   TreeNode* findLCA(TreeNode* root, int startValue, int destValue) {
        if (!root) return nullptr;
        if (root->val == startValue || root->val == destValue) return root;
        
        TreeNode* left = findLCA(root->left, startValue, destValue);
        TreeNode* right = findLCA(root->right, startValue, destValue);
        
        if (left && right) return root;
        return left ? left : right;
    }
    
    // Helper function to find the path from root to a given value
    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        
        path.push_back('L');
        if (findPath(root->left, value, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (findPath(root->right, value, path)) return true;
        path.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the LCA of startValue and destValue
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        // Find the path from LCA to startValue
        string pathToStart;
        findPath(lca, startValue, pathToStart);
        
        // Find the path from LCA to destValue
        string pathToDest;
        findPath(lca, destValue, pathToDest);
        
        // Convert the path to start to 'U' and append the path to dest
        string result(pathToStart.size(), 'U');
        result += pathToDest;
        
        return result;
    }
};