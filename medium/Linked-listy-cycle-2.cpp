/*
 * Title : Linked List Cycle - II
 * Problem Link : https://leetcode.com/problems/linked-list-cycle-ii/
 * Submission Link : https://leetcode.com/submissions/detail/508678441/
 */


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow  = head;
        ListNode* fast = head;
        if(head == NULL) return NULL;
        while(fast->next != NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
            
        }        
        if(fast==NULL || fast->next==NULL || fast->next->next==NULL) return NULL;
        fast = head;
            while(slow!= fast){
                slow  = slow->next;
                fast = fast->next;
            }    
        return slow;
    }
};