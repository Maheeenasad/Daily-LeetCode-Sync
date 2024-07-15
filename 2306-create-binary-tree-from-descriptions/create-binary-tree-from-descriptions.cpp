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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        // Process each description
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];
            
            // Create or retrieve the parent node
            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parentNode = nodes[parentVal];
            
            // Create or retrieve the child node
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }
            TreeNode* childNode = nodes[childVal];
            
            // Set the child as left or right
            if (isLeft) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
            
            // Mark this node as a child
            children.insert(childVal);
        }
        
        // The root is the node which is not in the children set
        TreeNode* root = nullptr;
        for (const auto& pair : nodes) {
            if (children.find(pair.first) == children.end()) {
                root = pair.second;
                break;
            }
        }
        
        return root; 
    }
};