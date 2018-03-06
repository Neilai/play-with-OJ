#include<iostream>
#include<stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    		int carry=0;
    		ListNode *result=new ListNode(0);
    		ListNode *p=result;
    		while(l1||l2){
    			if(l1&&l2){
    			   p->next=new ListNode(0);
    			   p->next->val=(l1->val+l2->val+carry)%10;
    			   carry=(l1->val+l2->val+carry)/10;
    			   l1=l1->next;
    			   l2=l2->next;
    			}
    			else if(l1&&!l2){
    				p->next->val=(l1->val+carry)%10;
    				carry=(l1->val+carry)/10;
    				l1=l1->next;
    			}
    			else{
    				p->next->val=(l2->val+carry)%10;
    				carry=(l2->val+carry)/10;
    				l2=l2->next;
    			}
    			p=p->next;
    		}
    		return result->next;
    }
};
int main(){
	return 1;
}