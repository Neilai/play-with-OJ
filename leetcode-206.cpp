#include<iostream>
using namespace std;
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *cur=head->next;
        ListNode *tmp;
        while(cur->next){
        	tmp=cur->next;
        	cur->next=pre;
        	pre=cur;
        	cur=tmp;
        }
        head->next=cur;
        return head;
    }
};


int main(){
	ListNode x(1);
	ListNode y(2);
	ListNode z(3);
	ListNode *head;
	cout<<&x;
	// x.next=&y;
	// y.next=&z;
	// Solution s;

	return 1;
}