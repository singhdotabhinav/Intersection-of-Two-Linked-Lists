//Program to find intersection of Singly linked list
//Step 1:Calculate the length of two lists
//Step 2:Find difference of two nodes length
//Step 3:Traverse the longer list to certain distance i.e, difference=count1-count2
//Step 4:After traversing longer list they both come at same relative position
//Step 5:Now, increment both one by one and compare
//Step 6:If they are equal then return that address

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
    
    int getCount(ListNode* head) { 
        ListNode* current = head; 
        int count = 0;  
        while (current != NULL){ 
            count++;  
            current = current->next; 
        }
        return count; 
    } 
    
    ListNode *getIntesectionNode(int d, ListNode* head1, ListNode* head2) { 
     
        ListNode* current1 = head1; 
        ListNode* current2 = head2; 
  
        // Move the pointer forward 
        for (int i = 0; i < d; i++) {  
            current1 = current1->next; 
         } 
  
        // Move both pointers of both list till they 
        // intersect with each other 
        while (current1 != NULL && current2 != NULL) { 
            if (current1 == current2) 
                return current1; 
            
            current1 = current1->next;
            current2 = current2->next;       
         }
        
        return current1;
  
    } 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int c1=getCount(headA);
        int c2=getCount(headB);
        int d; 
        
        if(c1>c2){
           d=c1-c2;
        }
        else{
           d=c2-c1;
        } 
        
        if(c1>c2){
            return getIntesectionNode(d,headA,headB);
        }
        else{
            return getIntesectionNode(d,headB,headA);
        }       
    }
};
