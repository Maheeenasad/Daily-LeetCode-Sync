class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        auto [pairs, _] = dfs(root, distance);
        return pairs;
    }

private:
    pair<int, vector<int>> dfs(TreeNode* node, int distance) {
        if (!node) return {0, {}};

        // If it's a leaf node, return the distance array containing just one element 1
        if (!node->left && !node->right) return {0, {1}};

        auto [leftPairs, leftDistances] = dfs(node->left, distance);
        auto [rightPairs, rightDistances] = dfs(node->right, distance);

        // Combine pairs from left and right subtrees
        int pairs = leftPairs + rightPairs;

        // Count pairs between left and right distances
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    ++pairs;
                }
            }
        }

        // Update distances
        vector<int> newDistances;
        for (int ld : leftDistances) {
            if (ld + 1 <= distance) {
                newDistances.push_back(ld + 1);
            }
        }
        for (int rd : rightDistances) {
            if (rd + 1 <= distance) {
                newDistances.push_back(rd + 1);
            }
        }

        return {pairs, newDistances};
    }
};
