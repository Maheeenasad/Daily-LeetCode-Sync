class Solution {
public:
    int numTeams(vector<int>& rating) {
         int n = rating.size();
        int count = 0;
        
        for (int j = 0; j < n; ++j) {
            int leftLess = 0, leftGreater = 0;
            int rightLess = 0, rightGreater = 0;
            
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) leftLess++;
                if (rating[i] > rating[j]) leftGreater++;
            }
            
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) rightLess++;
                if (rating[k] > rating[j]) rightGreater++;
            }
            
            count += leftLess * rightGreater + leftGreater * rightLess;
        }
        
        return count;
    }
};