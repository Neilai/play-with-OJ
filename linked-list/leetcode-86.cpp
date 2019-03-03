#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode  gt(0),lt(0);
        ListNode * plt=&lt;
        ListNode * pgt=&gt;
        ListNode * cur=head;
        while(cur){
        	if(cur->val<x){
	        	plt->next=cur;
	        	plt=plt->next;
        	}else{
	        	pgt->next=cur;
	        	pgt=pgt->next;
	        }	
	        cur=cur->next;
        }
        plt->next=gt.next;
        pgt->next=NULL;
        return lt.next;
    }
};
int main(){

}


// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         ListNode left(0), right(0);
//         ListNode *l = &left, *r = &right;

//         while(head){
//             ListNode* & ref = head->val < x ? l : r;
//             ref->next = head;
//             ref = ref->next;
//             head = head->next;
//         }
//         l->next = right.next;
//         r->next = NULL;
//         return left.next;
//     }
// };