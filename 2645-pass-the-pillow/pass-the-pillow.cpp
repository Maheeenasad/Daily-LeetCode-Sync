class Solution {
public:
    int passThePillow(int n, int time) {
      int currentPerson = 1;  // Start with the first person
        int direction = 1;  // 1 for forward, -1 for backward

        for (int i = 0; i < time; ++i) {
            currentPerson += direction;

            // Change direction if we reach the end of the line
            if (currentPerson == n + 1) {
                direction = -1;
                currentPerson = n - 1;
            } else if (currentPerson == 0) {
                direction = 1;
                currentPerson = 2;
            }
        }
        
        return currentPerson;
    }
};