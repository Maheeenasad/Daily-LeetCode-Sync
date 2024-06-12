class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate = 0;
    int count = 0;

    // Phase 1: Find the candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate (optional, since the majority element is guaranteed)
    // count = 0;
    // for (int num : nums) {
    //     if (num == candidate) {
    //         count++;
    //     }
    // }
    // if (count > nums.size() / 2) {
    //     return candidate;
    // } else {
    //     return -1; // This line is never reached because a majority element always exists.
    // }

    return candidate;


    }
};