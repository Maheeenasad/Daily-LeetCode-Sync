class Solution {
public:
    int numberOfMatches(int n) {
         int matches = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                // If number of teams is even
                matches += n / 2;
                n /= 2;
            } else {
                // If number of teams is odd
                matches += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        return matches;  
    }
};