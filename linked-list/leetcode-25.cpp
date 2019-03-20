#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseN(ListNode* head, int n) {
		ListNode *dummy=new ListNode(0),*pre=dummy,*cur=head;
		dummy->next=head;
		for(int i=0;i<n-1;i++){
		   ListNode* move = cur ->next;
           cur -> next = move ->next;
           move -> next = pre -> next;
           pre -> next = move;
		}
		return dummy->next;
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
    	ListNode *p=head,*prev;
    	int cnt=0;
    	while(p){
    		cnt++;
    		p=p->next;
    	}
    	p=head;
    	int turn=cnt/k;
    	for(int i=0;i<turn;i++){
    		if(i==0) head=reverseN(p,k);
    		else prev->next=reverseN(p,k);
    		prev=p;
    		p=p->next;
    	}
    	return head;
    }
};
int main(){

}


// class Solution {
// public:
//     ListNode *reverseKGroup(ListNode *head, int k) {
//         if(head==NULL||k==1) return head;
//         int num=0;
//         ListNode *preheader = new ListNode(-1);
//         preheader->next = head;
//         ListNode *cur = preheader, *nex, *pre = preheader;
//         while(cur = cur->next) 
//             num++;
//         while(num>=k) {
//             cur = pre->next;
//             nex = cur->next;
//             for(int i=1;i<k;++i) {
//                 cur->next=nex->next;
//                 nex->next=pre->next;
//                 pre->next=nex;
//                 nex=cur->next;
//             }
//             pre = cur;
//             num-=k;
//         }
//         return preheader->next;
//     }
// };