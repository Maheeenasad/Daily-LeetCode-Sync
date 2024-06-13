class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
          // Step 1: Sort both arrays
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int totalMoves = 0;
        
        // Step 2: Calculate the total number of moves
        for (int i = 0; i < seats.size(); ++i) {
            totalMoves += abs(seats[i] - students[i]);
        }
        
        return totalMoves;
    }
};