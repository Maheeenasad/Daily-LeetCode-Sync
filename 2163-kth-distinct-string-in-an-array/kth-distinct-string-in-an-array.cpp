class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;

        // Step 1: Count occurrences of each string
        for (const string& str : arr) {
            countMap[str]++;
        }

        // Step 2: Identify the distinct strings in order
        vector<string> distinctStrings;
        for (const string& str : arr) {
            if (countMap[str] == 1) {
                distinctStrings.push_back(str);
            }
        }

        // Step 3: Return the k-th distinct string or an empty string if not enough distinct strings
        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1];
        } else {
            return "";
        }
    }
};