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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
          unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        root = deleteNodes(root, toDeleteSet, result);
        
        // If the root is not deleted, add it to the result list
        if (root != nullptr) {
            result.push_back(root);
        }
        
        return result;
    }

private:
    TreeNode* deleteNodes(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& result) {
        if (node == nullptr) {
            return nullptr;
        }
        
        node->left = deleteNodes(node->left, toDeleteSet, result);
        node->right = deleteNodes(node->right, toDeleteSet, result);
        
        if (toDeleteSet.count(node->val)) {
            if (node->left != nullptr) {
                result.push_back(node->left);
            }
            if (node->right != nullptr) {
                result.push_back(node->right);
            }
            return nullptr;
        }
        
        return node;
    }
};