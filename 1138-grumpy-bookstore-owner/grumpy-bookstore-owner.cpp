class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
                int n = customers.size();
        
        // Calculate the initial satisfaction without any technique
        int totalSatisfaction = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                totalSatisfaction += customers[i];
            }
        }
        
        // Sliding window to find the maximum additional satisfaction
        int additionalSatisfaction = 0;
        int maxAdditionalSatisfaction = 0;
        
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 1) {
                additionalSatisfaction += customers[i];
            }
            
            if (i >= minutes && grumpy[i - minutes] == 1) {
                additionalSatisfaction -= customers[i - minutes];
            }
            
            maxAdditionalSatisfaction = max(maxAdditionalSatisfaction, additionalSatisfaction);
        }
        
        return totalSatisfaction + maxAdditionalSatisfaction;
    
    }
};