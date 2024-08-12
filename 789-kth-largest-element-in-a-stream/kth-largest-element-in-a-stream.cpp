#include <queue>
#include <vector>

class KthLargest {
public:
    // Min-heap to keep the top k largest elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k;

    // Constructor to initialize the class with k and the nums array
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num); // Add elements to the heap
        }
    }

    // Function to add a value to the stream
    int add(int val) {
        minHeap.push(val); // Add the value to the min-heap
        if (minHeap.size() > k) {
            minHeap.pop(); // Ensure the heap size remains k by removing the smallest element
        }
        return minHeap.top(); // The kth largest element will be at the top of the heap
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
