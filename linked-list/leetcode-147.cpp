#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy=new ListNode(0),*cur=head,*prev=cur;
        dummy->next=head;
        while(cur){
        	ListNode *p=dummy->next,*prev_p=dummy;
        	while(p!=cur&&p->val<cur->val){   		
        		prev_p=p;
        		p=p->next;
        	}
        	if(p!=cur){
        		prev_p->next=cur;
        		prev->next=cur->next;
        		cur->next=p;
        		cur=prev->next;
        	}else{
        		prev=cur;
        		cur=cur->next;	
        	} 
        }
        return dummy->next;
    }
};
int main(){
	ListNode x1(5);
	ListNode x2(4);
	ListNode x3(3);
	ListNode x4(2);
	ListNode x5(1);
	
	x1.next=&x2;
	x2.next=&x3;
	x3.next=&x4;
	x4.next=&x5;
	
	Solution s;
	ListNode *p=s.insertionSortList(&x1);
	// cout<<p->next->next->next->next->val;
	while(p){
		cout<<p->val<<ends;
		p=p->next;
	}
}


// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode* dummy = new ListNode(0);
//         dummy -> next = head;
//         ListNode *pre = dummy, *cur = head;
//         while (cur) {
//             if ((cur -> next) && (cur -> next -> val < cur -> val)) {
//                 while ((pre -> next) && (pre -> next -> val < cur -> next -> val)) {
//                     pre = pre -> next;
//                 }
//                 ListNode* temp = pre -> next;
//                 pre -> next = cur -> next;
//                 cur -> next = cur -> next -> next;
//                 pre -> next -> next = temp;
//                 pre = dummy;
//             }
//             else {
//                 cur = cur -> next;
//             }
//         }
//         return dummy -> next;
//     }
// };