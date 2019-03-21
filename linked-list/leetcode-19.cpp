class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0),*p=dummy,*q=dummy;
       dummy->next=head;
       for(int i=0;i<n+1;i++){
       		q=q->next;
       }
       while(q!=NULL){
       	  p=p->next;
       	  q=q->next;
       }
       p->next=p->next->next;
       return dummy->next;
    }
};