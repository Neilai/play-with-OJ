#include<iostream>
using namespace std;
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x) {}
};
 // 妈耶 链表反转也能把我搞出bug
// 问题出在循环  要搞清楚循环变量的意义  也就是到达while点的时候，变量的意义 ，cur意味着当前需要改变指向的链表
// 另外链表题一定要注意一下空的情况
// 还有吐槽一下也没说下链表有没有头指针啥的 = =
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
        	return head;
        ListNode *pre=nullptr;
        ListNode *cur=head;
        ListNode *tmp;
        while(cur){
        	tmp=cur->next;
        	cur->next=pre;
        	pre=cur;
        	cur=tmp;
            
        }
        return pre;
    }
};
int main(){

	ListNode x(1);
	ListNode y(2);
	ListNode z(3);
	ListNode *head;
	head->next=head;
	head->next=&x;
	// cout<<x.val;
	cout<<head->next->val;
	// x.next=&y;
	// y.next=&z;
	// Solution s;

	return 1;
}