#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        dist[1] = 0;

        queue<pair<int, int>> q;
        q.push({1, 0}); // {node, current_distance}

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (dist[neighbor] > d + 1) {
                    dist2[neighbor] = dist[neighbor];
                    dist[neighbor] = d + 1;
                    q.push({neighbor, dist[neighbor]});
                } else if (dist[neighbor] < d + 1 && dist2[neighbor] > d + 1) {
                    dist2[neighbor] = d + 1;
                    q.push({neighbor, dist2[neighbor]});
                }
            }
        }

        int secondShortest = dist2[n];

        return calculateTravelTime(secondShortest, time, change);
    }

private:
    long long calculateTravelTime(int edges, int time, int change) {
        long long totalTravelTime = 0;
        for (int i = 0; i < edges; ++i) {
            totalTravelTime += time;
            if (i < edges - 1) {
                if ((totalTravelTime / change) % 2 == 1) {  // Red light
                    totalTravelTime = (totalTravelTime / change + 1) * change;
                }
            }
        }
        return totalTravelTime;
    }
};
