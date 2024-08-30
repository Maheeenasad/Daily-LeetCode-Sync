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
    ListNode* removeElements(ListNode* head, int val) {
          // Create a dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* current = &dummy; // Start from the dummy node
        
        while (current->next != nullptr) {
            if (current->next->val == val) {
                // Skip the node with value equal to 'val'
                ListNode* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete; // Free memory of removed node
            } else {
                // Move to the next node
                current = current->next;
            }
        }
        
        return dummy.next; // Return the new head
    }
};