class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // k will be the number of elements not equal to val

    // Traverse the array

    for (int i = 0; i < nums.size(); ++i) {

        if (nums[i] != val) {

            // If the current element is not equal to val,

            // place it at the next position of the array

            nums[k] = nums[i];

            ++k;

        }

    }

    // k now contains the number of elements not equal to val

    return k;
    }
};