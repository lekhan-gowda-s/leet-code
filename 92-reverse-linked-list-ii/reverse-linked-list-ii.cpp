class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Dummy node handles the case when left == 1
        ListNode dummy(0);
        dummy.next = head;

        // prev will point to the node before the reversal
        ListNode* prev = &dummy;

        // Move prev to position left - 1
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node that needs to be reversed
        ListNode* curr = prev->next;

        // Reverse the nodes from left to right
        for (int i = 0; i < right - left; i++) {
            ListNode* next = curr->next;

            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};