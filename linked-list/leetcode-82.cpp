#include<iostream>
using namespace std;
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x) {}
};
// 解法一  不使用虚拟头节点
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
    				// 删除元素如果不用头节点的话需要对删除首元素单独判断
    				if(!prev){
    					ListNode *tmp=cur;
						cur=cur->next;
						del=tmp->val;
						head=cur;
    				}
    				else{
						prev->next=cur->next;
						ListNode *tmp=cur;
						cur=cur->next;
						del=tmp->val;
						// delete tmp;
					}
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

// 解法二 使用头节点 不需要单独判断首元素删除 而且不需要prev指针，比较方便
// 实际上考虑的是删除后面一个元素
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        int duplicate;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                duplicate = cur->next->val;
                while (cur->next && cur->next->val == duplicate) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
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