class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
          int n = source.size();
        int INF = INT_MAX / 2; // To avoid overflow when adding two INF values
        
        vector<vector<int>> dist(26, vector<int>(26, INF));
        
        // Initialize distances
        for (int i = 0; i < 26; ++i) {
            dist[i][i] = 0;
        }
        
        // Fill the initial distances from given transformations
        int m = original.size();
        for (int i = 0; i < m; ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        
        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        // Calculate the minimum cost to convert source to target
        long long totalCost = 0;
        for (int i = 0; i < n; ++i) {
            int sChar = source[i] - 'a';
            int tChar = target[i] - 'a';
            if (dist[sChar][tChar] == INF) {
                return -1; // Impossible to convert
            }
            totalCost += dist[sChar][tChar];
        }
        
        return totalCost;
    }
};