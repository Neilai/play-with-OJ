#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur=head;
        ListNode *prev=nullptr;
        while(cur&&cur->next){
        	ListNode *tmp=cur->next->next;
        	prev->next=cur->next;
        	cur->next->next=cur;
        	cur->next=tmp;
        	prev=cur;
        	cur=tmp;
        }
        return head;
    }
};
int main(){}