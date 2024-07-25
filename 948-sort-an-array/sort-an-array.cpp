#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Create temporary arrays
        vector<int> L(n1);
        vector<int> R(n2);
        
        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = nums[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = nums[mid + 1 + j];
        
        // Merge the temporary arrays back into nums[left..right]
        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        int k = left; // Initial index of merged subarray
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            } else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        
        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }
        
        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = left + (right - left) / 2;
            
            // Sort first and second halves
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            
            // Merge the sorted halves
            merge(nums, left, mid, right);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
