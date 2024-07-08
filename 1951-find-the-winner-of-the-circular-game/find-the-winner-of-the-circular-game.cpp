class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Base case: Josephus(1, k) = 0
        
        // Iteratively calculate the position for larger circles
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        
        // Convert 0-based index to 1-based index
        return winner + 1; 
    }
};