class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       // Step 1: Calculate the total chalk usage in one full round
        long long total_chalk = 0;
        for (int ch : chalk) {
            total_chalk += ch;
        }
        
        // Step 2: Reduce k by the total chalk usage in complete rounds
        k %= total_chalk;
        
        // Step 3: Identify the student who will replace the chalk
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1;  // This line should never be reached  
    }
};