/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
         // To store the indices of critical points
        vector<int> criticalPoints;
        
        // Initialize pointers
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;  // Start from the second node
        
        // Traverse the linked list
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* next = curr->next;
            
            // Check if the current node is a local minima or maxima
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(index);
            }
            
            // Move the pointers forward
            prev = curr;
            curr = next;
            index++;
        }
        
        // If there are fewer than 2 critical points, return [-1, -1]
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        // Calculate the minimum and maximum distances between critical points
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        for (int i = 1; i < criticalPoints.size(); ++i) {
            int distance = criticalPoints[i] - criticalPoints[i - 1];
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
        
        return {minDistance, maxDistance};
    }
};