 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        return partitionHelper(lists,0 , lists.size()-1);        
    }
    ListNode* partitionHelper(vector<ListNode*>& lists , int start , int end){
       if(start==end){
           return lists[start];
       } 
        
       int mid = (start+end)/2;
      ListNode* head1 = partitionHelper(lists  ,start , mid);
      ListNode* head2 = partitionHelper(lists,mid+1 , end);
       return mergeList(head1 , head2); 
    }
    ListNode* mergeList(ListNode* l1 , ListNode* l2){
        
        ListNode* dummy = new ListNode();
        ListNode* tempNode= dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tempNode->next = l1;
                l1 = l1->next;
            }
            else{
                tempNode->next = l2;
                    l2 = l2->next;
            }
            tempNode = tempNode->next;
        }
        if(l1) tempNode->next = l1;
        if(l2) tempNode->next = l2;
        
        return dummy->next;
    }
};