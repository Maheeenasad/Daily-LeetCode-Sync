class Solution {
public:
    int minimumDeletions(string s) {
            int n = s.size();
        int countB = 0; // To count 'b's
        int minDeletions = 0;
        
        // Iterate through the string
        for (char c : s) {
            if (c == 'b') {
                countB++; // Increment count of 'b'
            } else { // c == 'a'
                // If there's an 'a' and we have 'b's before it
                if (countB > 0) {
                    minDeletions++; // Consider deleting this 'a'
                    countB--; // As if we deleted a 'b' before it to balance
                }
            }
        }
        
        return minDeletions;
    }
};