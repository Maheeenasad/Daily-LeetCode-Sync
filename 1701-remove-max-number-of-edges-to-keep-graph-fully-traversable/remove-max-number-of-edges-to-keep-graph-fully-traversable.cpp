#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 1), count(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    bool unionSet(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // Already connected
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        count--;
        return true;
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufA(n), ufB(n);
        int removeCount = 0;

        // Process type 3 edges (usable by both Alice and Bob)
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                bool mergedA = ufA.unionSet(edge[1] - 1, edge[2] - 1);
                bool mergedB = ufB.unionSet(edge[1] - 1, edge[2] - 1);
                if (!mergedA && !mergedB) {
                    removeCount++;
                }
            }
        }

        // Process type 1 edges (Alice only)
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (!ufA.unionSet(edge[1] - 1, edge[2] - 1)) {
                    removeCount++;
                }
            }
        }

        // Process type 2 edges (Bob only)
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (!ufB.unionSet(edge[1] - 1, edge[2] - 1)) {
                    removeCount++;
                }
            }
        }

        // Check if both Alice and Bob can traverse the entire graph
        if (ufA.getCount() != 1 || ufB.getCount() != 1) {
            return -1;
        }

        return removeCount;
    }
};

