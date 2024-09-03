class Solution {
public:
    int getLucky(string s, int k) {
          // Step 1: Convert the string into the corresponding number string
        std::string numStr = "";
        for (char c : s) {
            numStr += std::to_string(c - 'a' + 1);  // Convert each character to its alphabet position
        }
        
        // Step 2: Convert numStr to an integer sum and perform k transformations
        int sum = 0;
        for (char c : numStr) {
            sum += c - '0';  // Sum the digits of the number string
        }
        
        // Step 3: Perform the sum of digits transformation k-1 more times
        for (int i = 1; i < k; ++i) {
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }
        
        return sum;
    }
};