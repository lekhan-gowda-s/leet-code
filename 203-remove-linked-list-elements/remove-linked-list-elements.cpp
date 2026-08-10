class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching nodes from the beginning
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // Remove matching nodes from the middle/end
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {

            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } 
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};
