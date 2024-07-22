class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
   int n = names.size();
        vector<pair<int, string>> people;
        
        // Pairing heights with names
        for (int i = 0; i < n; ++i) {
            people.emplace_back(heights[i], names[i]);
        }
        
        // Sorting pairs by height in descending order
        sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        
        // Extracting sorted names
        vector<string> sortedNames;
        for (const auto& person : people) {
            sortedNames.push_back(person.second);
        }
        
        return sortedNames;
    }
};