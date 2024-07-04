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
    ListNode* mergeNodes(ListNode* head) {
         // Create a dummy node to ease list creation
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Pointer to traverse the input list
        ListNode* ptr = head->next; // Skip the initial zero node
        
        int sum = 0;
        
        while (ptr != nullptr) {
            if (ptr->val == 0) {
                // End of a segment, create a new node with the sum
                current->next = new ListNode(sum);
                current = current->next;
                // Reset the sum
                sum = 0;
            } else {
                // Accumulate the sum
                sum += ptr->val;
            }
            ptr = ptr->next;
        }
        
        return dummy->next;
    }
};