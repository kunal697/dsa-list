class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* dummyNode  = new ListNode();
       ListNode* tempNode = new ListNode();
       tempNode = dummyNode;
       
       while(list1 && list2){
           
           if(list1->val < list2->val){
               tempNode->next = list1;
               list1 = list1->next;
           }
           else{
               tempNode->next = list2;
               list2 = list2->next;
           }
           tempNode = tempNode->next;
       }
        
        
       if(list1) tempNode->next = list1;
        if(list2) tempNode->next = list2;
        
       
        return dummyNode->next;
        
    }
};