#include<iostream>
using namespace std;
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head)
    		return head;
    	ListNode *cur=head;
    	ListNode *prev=nullptr;
    	int del;
    	while(cur){
    		if(cur->next&&cur->val==cur->next->val){
    			do{
    				if(prev)
    					prev->next=cur->next;
					ListNode *tmp=cur;
					cur=cur->next;
					del=tmp->val;
					delete tmp;
    			} while(cur&&del==cur->val);
    		}
    		else{
    			prev=cur;
    			cur=cur->next;
    		}
    	}
    	return head;
    }
};
int main(){
	ListNode *x=new ListNode(1);
	ListNode *y=new ListNode(2);
	ListNode *z=new ListNode(2);
	x->next=y;
	y->next=z;
	Solution s;
	s.deleteDuplicates(x);
	// cout<<	
}