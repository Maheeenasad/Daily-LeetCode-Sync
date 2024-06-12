class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
    
    // Start from the last digit and move to the left
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            // If current digit is less than 9, just increment it and return the result
            digits[i]++;
            return digits;
        }
        // If current digit is 9, set it to 0 (carry over)
        digits[i] = 0;
    }
    
    // If all digits were 9, we have a carry over resulting in a new most significant digit
    digits.insert(digits.begin(), 1);
    return digits;



    }
};