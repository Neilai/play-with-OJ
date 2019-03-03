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
	        	ListNode *newNode=new ListNode(cur->val);
	        	
	        	plt->next=newNode;
	        	plt=plt->next;
        	}else{
	        	ListNode *newNode=new ListNode(cur->val);
	        	newNode->val=cur->val;
	        	pgt->next=newNode;
	        	pgt=pgt->next;
	        }	
	        cur=cur->next;
        }
        plt->next=gt.next;
        return lt.next;
    }
};
int main(){

}