class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int maxWealth = 0;
        
        for (const auto& customer : accounts) {
            int currentWealth = 0;
            for (int account : customer) {
                currentWealth += account;
            }
            if (currentWealth > maxWealth) {
                maxWealth = currentWealth;
            }
        }
        
        return maxWealth;  
    }
};