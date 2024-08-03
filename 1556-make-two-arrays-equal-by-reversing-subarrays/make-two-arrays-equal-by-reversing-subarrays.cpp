class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // If sizes are not equal, return false immediately
        if (target.size() != arr.size()) {
            return false;
        }

        // Use unordered maps to count the frequencies of elements in both arrays
        unordered_map<int, int> targetCount, arrCount;

        for (int num : target) {
            targetCount[num]++;
        }

        for (int num : arr) {
            arrCount[num]++;
        }

        // Compare the frequency maps
        return targetCount == arrCount;  
    }
};