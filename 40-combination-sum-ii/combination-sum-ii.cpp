class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> currentCombination;
        backtrack(candidates, target, 0, currentCombination, results);
        return results;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& currentCombination, vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(currentCombination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // If the current candidate exceeds the target, no need to continue
            if (candidates[i] > target) {
                break;
            }

            // Include the current candidate and move forward
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, currentCombination, results);
            // Exclude the current candidate (backtrack)
            currentCombination.pop_back();
        }
    }
};