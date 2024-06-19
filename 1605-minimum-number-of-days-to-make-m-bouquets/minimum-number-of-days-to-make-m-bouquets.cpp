class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
          long long n = bloomDay.size();
        // If we can't have enough flowers to make m bouquets, return -1
        if (n < static_cast<long long>(m) * k) return -1;

        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());

        auto canMakeBouquets = [&](int day) -> bool {
            int bouquets = 0, flowers = 0;
            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] <= day) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
                if (bouquets >= m) return true;
            }
            return false;
        };

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};