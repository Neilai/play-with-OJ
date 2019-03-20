#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	// 这种解法有最大整数限制
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		  //       ListNode* result=new ListNode(0);
		  //       stack<unsigned long long> s;
		        
		  //       while(l1){
		  //       	s.push(l1->val);
		  //       	l1=l1->next;
		  //       }
		  //       unsigned long long a=0;
		  //       while(!s.empty()){
		  //       	a=a*10;
		  //       	unsigned long long tmp=s.top();
		  //       	a+=tmp;
		  //       	s.pop();
		  //       }

		  //       while(l2){
		  //       	s.push(l2->val);
		  //       	l2=l2->next;
		  //       }
		  //       unsigned long long b=0;
		  //       while(!s.empty()){
		  //       	b=b*10;
		  //       	unsigned long long tmp=s.top();
		  //       	b+=tmp;
		  //       	s.pop();
		  //       }

		  //       unsigned long long c=a+b;
		  //       ListNode *p=result;	
		        
		  //       p->val=c%10;
		  //       c/=10;
		        
		  //       while(c){
		  //       	p->next=new ListNode;
		  //       	p->next->val=c%10;
		  // 			p=p->next;
		  //       	c/=10;
		  //       }
		  //       return result;
    // }
    // 一般来说是把结果结点声明 然后新增结点不断放到next指针后面 最后返回result->next
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    		int carry=0;
    		ListNode *result=new ListNode(0);
    		ListNode *p=result;
    		while(l1||l2){
    			int sum=(l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
    			p->next = new ListNode(sum%10);
    			carry = sum/10;
    			p  = p->next;
		        l1 = l1 ? l1->next : l1;
		        l2 = l2 ? l2->next : l2;
    		}
    		if(carry==1)
    			p->next=new ListNode(1);
    		return result->next;
    }
};
int main(){
	return 1;
}



ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}