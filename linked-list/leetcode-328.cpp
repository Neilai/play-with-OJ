#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	ListNode * oddptr=head, *evenptr=head->next;
    	while(evenptr&&evenptr->next){
    		oddptr->next=evenptr->next;
    		oddptr=oddptr->next;
    		evenptr->next=oddptr->next;
    		evenptr=evenptr->next;
    	}
    	oddptr->next=evenptr;
        return head;
    }
};
int main(){
	ListNode x1(1);
	ListNode x2(2);
	ListNode x3(3);
	ListNode x4(4);
	ListNode x5(5);
	
	x1.next=&x2;
	x2.next=&x3;
	x3.next=&x4;
	x4.next=&x5;
	
	Solution s;
	s.oddEvenList(&x1);
}