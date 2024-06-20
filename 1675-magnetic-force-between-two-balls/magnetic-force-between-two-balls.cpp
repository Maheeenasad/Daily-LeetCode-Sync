class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
     sort(position.begin(), position.end());
        int left = 1, right = position.back() - position.front();
        
        auto canPlaceBalls = [&](int d) -> bool {
            int count = 1;  // Place the first ball in the first basket
            int last_pos = position[0];
            
            for (int i = 1; i < position.size(); ++i) {
                if (position[i] - last_pos >= d) {
                    count++;
                    last_pos = position[i];
                }
                if (count >= m) return true;
            }
            return false;
        };
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBalls(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
        
             
    }
};