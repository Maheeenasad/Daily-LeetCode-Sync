class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
          // Ensure we don't access out-of-bounds elements
        if (arr.size() < 3) {
            return false;
        }

        // Traverse the array up to the third last element
        for (int i = 0; i <= arr.size() - 3; ++i) {
            // Check if the current element and the next two are all odd
            if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
                return true;
            }
        }
        // If no three consecutive odd numbers are found
        return false;
    }
};