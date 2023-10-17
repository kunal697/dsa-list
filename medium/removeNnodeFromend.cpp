// [Question](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
         ListNode *temp = head,*prev;
           while(temp!=nullptr)
           {
               temp = temp->next;
               count++;
           }
                temp = head;
           if(count-n==0)
           {
                 head=head->next;
                 delete temp;
                 return head;
             }
           for(int i  =1;i<=count-n;i++)
           {
               prev = temp;
               temp = temp->next;
           }
      
           prev->next = temp->next;
           delete temp;
           temp = nullptr;

           return head;
           
    }
};
