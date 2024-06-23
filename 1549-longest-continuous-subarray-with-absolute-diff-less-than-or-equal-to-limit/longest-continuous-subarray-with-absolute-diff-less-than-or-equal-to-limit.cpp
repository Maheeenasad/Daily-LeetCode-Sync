class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
         deque<int> maxDeque, minDeque;
        int left = 0, right = 0, maxLength = 0;

        while (right < nums.size()) {
            // Maintain the max deque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain the min deque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Check the window's condition
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }

            // Calculate the max length of the subarray
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};