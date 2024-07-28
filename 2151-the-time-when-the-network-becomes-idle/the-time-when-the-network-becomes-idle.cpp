#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Step 2: Use BFS to find the shortest paths from node 0 to all other nodes
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Calculate the idle time for each server
        int maxTime = 0;
        for (int i = 1; i < n; ++i) {
            int roundTripTime = 2 * dist[i];
            int lastMessageTime = 0;
            
            if (roundTripTime > patience[i]) {
                int lastResendTime = ((roundTripTime - 1) / patience[i]) * patience[i];
                lastMessageTime = lastResendTime + roundTripTime;
            } else {
                lastMessageTime = roundTripTime;
            }
            
            maxTime = max(maxTime, lastMessageTime);
        }
        
        // Step 4: Determine when the network becomes idle
        return maxTime + 1;
    }
};
