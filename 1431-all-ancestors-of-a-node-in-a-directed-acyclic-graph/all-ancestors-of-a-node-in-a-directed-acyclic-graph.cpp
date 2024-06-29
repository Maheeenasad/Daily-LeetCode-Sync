class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         // Step 1: Build the adjacency list and in-degree array
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Step 2: Perform topological sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topologicalOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topologicalOrder.push_back(node);
            for (int neighbor : adj[node]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Initialize ancestor sets
        vector<unordered_set<int>> ancestors(n);

        // Step 4: Process nodes in topological order
        for (int node : topologicalOrder) {
            for (int neighbor : adj[node]) {
                ancestors[neighbor].insert(node);
                ancestors[neighbor].insert(ancestors[node].begin(), ancestors[node].end());
            }
        }

        // Step 5: Convert ancestor sets to sorted lists
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            sort(result[i].begin(), result[i].end());
        }

        return result;
    }
};