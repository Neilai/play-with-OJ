#include<iostream>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur=head;
        ListNode *pev=nullptr;
        while(cur){
        	if(prev&&prev->val==cur->val){
        		prev->next=cur->next;
        		ListNode *tmp=cur;
        		cur=cur->next;
        		delete tmp;
        	}
        	else{
        		prev=cur;
        		cur=cur->next;
        	}
        };
        return head;
    }
};
