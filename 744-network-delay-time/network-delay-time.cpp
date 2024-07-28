#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }

        // Min-heap to store {time to reach node, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        
        // Distance vector to track shortest time to reach each node
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if (currTime > dist[node]) continue;  // If this path is not optimal, skip it

            for (const auto& [neighbor, time] : graph[node]) {
                int newTime = currTime + time;
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }

        // Find the maximum time to reach any node
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;  // If any node is unreachable
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
