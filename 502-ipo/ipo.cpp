class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         // Combine the profits and capital into a vector of pairs and sort by capital
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());

        // Max-heap to store the profits of projects we can afford
        priority_queue<int> maxHeap;
        
        int index = 0;
        for (int i = 0; i < k; ++i) {
            // Push all projects that can be started with current capital into the heap
            while (index < projects.size() && projects[index].first <= w) {
                maxHeap.push(projects[index].second);
                ++index;
            }

            // If the heap is empty, we can't start any more projects
            if (maxHeap.empty()) {
                break;
            }

            // Pop the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};