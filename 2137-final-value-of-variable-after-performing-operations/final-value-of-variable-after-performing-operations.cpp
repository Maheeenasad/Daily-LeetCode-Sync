class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;  // Initialize X to 0
        for (const auto& operation : operations) {
            if (operation == "++X" || operation == "X++") {
                X++;  // Increment X by 1
            } else if (operation == "--X" || operation == "X--") {
                X--;  // Decrement X by 1
            }
        }
        return X;  // Return the final value of X
    }
};