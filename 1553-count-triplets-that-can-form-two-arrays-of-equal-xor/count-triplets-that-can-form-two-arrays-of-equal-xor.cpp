class Solution {
public:
    int countTriplets(vector<int>& arr) {
          int n = arr.size();
        int count = 0;
        
        vector<int> prefixXOR(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefixXOR[i] == prefixXOR[k + 1]) {
                    count += (k - i); 
                }
            }
        }
        
        return count;
    }
};