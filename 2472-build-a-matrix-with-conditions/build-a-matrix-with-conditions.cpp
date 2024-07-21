class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
         // Helper function to perform topological sort
        auto topologicalSort = [&](int n, vector<vector<int>>& conditions) -> vector<int> {
            vector<int> inDegree(n + 1, 0);
            unordered_map<int, vector<int>> graph;
            for (auto& condition : conditions) {
                int u = condition[0], v = condition[1];
                graph[u].push_back(v);
                inDegree[v]++;
            }

            queue<int> q;
            for (int i = 1; i <= n; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }

            vector<int> topoOrder;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                topoOrder.push_back(node);
                for (int neighbor : graph[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            if (topoOrder.size() == n) {
                return topoOrder;
            } else {
                return {};  // cycle detected
            }
        };

        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {};  // no valid solution due to a cycle in row or column conditions
        }

        unordered_map<int, int> rowIndex, colIndex;
        for (int i = 0; i < k; ++i) {
            rowIndex[rowOrder[i]] = i;
            colIndex[colOrder[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            matrix[rowIndex[i]][colIndex[i]] = i;
        }

        return matrix;
    }
};