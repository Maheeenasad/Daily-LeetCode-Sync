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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            // Store next node
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move prev and current one step forward
            prev = current;
            current = next;
        }
        
        // prev will be the new head of the reversed list
        return prev;
    }
};