class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
         // Combine difficulty and profit into a list of pairs and sort by difficulty
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());

        // Sort workers by their ability
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int totalProfit = 0;
        int jobIndex = 0;
        
        // Iterate over each worker
        for (int ability : worker) {
            // Update maxProfit for the current ability
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= ability) {
                maxProfit = max(maxProfit, jobs[jobIndex].second);
                ++jobIndex;
            }
            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};