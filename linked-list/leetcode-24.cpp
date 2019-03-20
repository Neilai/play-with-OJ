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

        // 注意头节点要分开讨论
        if(cur&&cur->next){
        	head=cur->next;
        	ListNode *tmp=cur->next->next;
        	cur->next->next=cur;
        	cur->next=tmp;
        	prev=cur;
        	cur=tmp;

        }
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

// 链表里面最好用一个头指针  这样既可以避免记录prev  也可以避免头指针丢失问题
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
   		ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while(cur->next&&cur->next->next){
        	ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            p = node1;
        }

        ListNode* retHead = dummyHead->next;
        delete dummyHead;
        return retHead;
    }		        
	
};
int main(){

}