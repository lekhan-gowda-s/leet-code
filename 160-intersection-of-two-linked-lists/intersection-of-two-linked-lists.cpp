/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) 
    {
        //   FIRST APPROACH
        // stack<ListNode*> s1;
        // stack<ListNode*> s2;
        // ListNode * t1=h1;
        // ListNode * t2=h2;
        // while(t1!=NULL)     //tc=o(n)
        // {
        //     s1.push(t1);
        //     t1=t1->next;
        // }
        // while(t2!=NULL)     //tc=o(n)
        // {
        //     s2.push(t2);       // these 2 stacks will take sc = o(2n)
        //     t2=t2->next;   
        // }
        // t1=h1;
        // ListNode* prev=NULL;
        // while(!s1.empty() && !s2.empty()) //tc=o(n)
        // {
        //     if(s1.top()==s2.top())
        //     {
        //         prev=s1.top();
        //         s1.pop();
        //         s2.pop();
        //         t1=t1->next;   
        //     }
        //     else
        //     {
        //         break;
        //     }                   // overall tc = o(3n)
        // }                       // overall sc = o(2n)
        // return prev;
        ListNode * t1=h1;
        ListNode * t2=h2;
        int c1=0;
        int c2=0;
        while(t1!=NULL)
        {
            c1++;
            t1=t1->next;
        }
         while(t2!=NULL)
        {
            c2++;
            t2=t2->next;
        }
        t1=h1;
        t2=h2;
        if(c1>c2)
        {
            int d=c1-c2;
            for(int i=0;i<d;i++)
            {
              t1=t1->next;  
            }
        }
        else
        {
            int d=c2-c1;
            for(int i=0;i<d;i++)
            {
              t2=t2->next;  
            }
        }
        while(t1!=t2)
        {
            t1=t1->next;
            t2=t2->next;
            if(t1==t2) return t1;
        }
        if(t1==t2) return t1;
        return NULL;

    }
};