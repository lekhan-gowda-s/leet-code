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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* findKNode(ListNode* temp, int k)
    {
        k--;

        while(temp != NULL && k > 0)
        {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(head == NULL || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL)
        {
            ListNode* kNode = findKNode(temp, k);

            if(kNode == NULL)
            {
                if(prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kNode->next;
            kNode->next = NULL;

            ListNode* newHead = reverseList(temp);

            if(temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            temp->next = nextNode;

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};