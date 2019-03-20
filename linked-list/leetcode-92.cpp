#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

//使用dummy
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt=1;
        ListNode *tmp;
        ListNode *pre;
        ListNode *cur=head;
        
        ListNode *first;
        ListNode *last;
        ListNode *beforeFirst;
        ListNode *afterLast;
        //第一个
		if(m!=1){
			while(cnt<m-1){
				cur=cur->next;
				cnt++;
			}
			beforeFirst=cur;
			first=cur=cur->next;
			cnt++;  
		}
		else{
			beforeFirst=nullptr;
			first=cur;
		}
		//m n相等
		if(n!=m){
			pre=cur;
			cur=cur->next;
			cnt++;  
		}
        while(cnt<n){
        	tmp=cur->next;
        	cur->next=pre;
        	pre=cur;
        	cur=tmp;
        	cnt++;
        }
        last=cur;
        afterLast=cur->next;
        last->next=pre;
        if(beforeFirst)
        	beforeFirst->next=last;
        else 
        	head=last;
        first->next=afterLast;
        return head;
    }
};
int main(){
	ListNode x1(1);
	ListNode x2(2);
	ListNode x3(3);
	ListNode x4(4);
	ListNode x5(5);
	x1.next=&x2;
	x2.next=&x3;
	x3.next=&x4;
	x4.next=&x5;
	Solution s;
	ListNode *p=s.reverseBetween(&x1,2,2);
	while(p){
		cout<<p->val<<endl;
		p=p->next;
	}
}


class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy;
       dummy -> next = head;
       for (int i = 1; i < m; i++) {
           pre = pre -> next;
       }
       ListNode* cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* move = cur ->next;
           cur -> next = move ->next;
           move -> next = pre -> next;
           pre -> next = move;
       }
       return dummy -> next;
   }
};