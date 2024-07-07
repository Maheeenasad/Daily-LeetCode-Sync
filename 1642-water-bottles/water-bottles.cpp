class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottlesDrunk = 0;
        int emptyBottles = 0;
        
        while (numBottles > 0) {
            // Drink all current full bottles
            totalBottlesDrunk += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            
            // Exchange empty bottles for full ones
            if (emptyBottles >= numExchange) {
                numBottles = emptyBottles / numExchange;
                emptyBottles = emptyBottles % numExchange;
            }
        }
        
        return totalBottlesDrunk;  
    }
};