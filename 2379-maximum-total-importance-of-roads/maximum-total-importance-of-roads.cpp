class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         // Step 1: Calculate the degree of each city
        vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Step 2: Create a list of city indices and sort by degree in descending order
        vector<int> cities(n);
        for (int i = 0; i < n; ++i) {
            cities[i] = i;
        }
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        
        // Step 3: Assign values from n to 1 to cities based on their sorted order
        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            values[cities[i]] = n - i;
        }
        
        // Step 4: Calculate the total importance
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += values[road[0]] + values[road[1]];
        }
        
        return totalImportance;
    }
};