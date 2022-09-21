/*
 * Title : Linked List Cycle
 * Problem Link : https://leetcode.com/problems/linked-list-cycle/
 * Submission Link : https://leetcode.com/submissions/detail/720976227/
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode* slow  = head , *fast = head;
        
        while( fast && fast->next ){
            slow = slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return true;
        }
        return false;
    }
};



 