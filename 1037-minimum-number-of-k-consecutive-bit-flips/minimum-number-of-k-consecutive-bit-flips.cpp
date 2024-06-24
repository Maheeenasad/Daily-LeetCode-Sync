class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
                int n = nums.size();
        vector<int> flip(n, 0);
        int flips = 0, result = 0;

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flips ^= flip[i - k];
            }
            if ((nums[i] ^ flips) == 0) { // Need to flip at this position
                if (i + k > n) {
                    return -1;
                }
                flip[i] = 1;
                flips ^= 1;
                result++;
            }
        }
        return result;

    }
};