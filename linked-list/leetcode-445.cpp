#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

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

    ListNode* addTwoNumbers_reverse(ListNode* l1, ListNode* l2){
            int carry=0;
            ListNode *result=new ListNode(0);
            ListNode *p=result;
            while(l1||l2){
                int sum=(l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return  reverseList(addTwoNumbers_reverse(reverseList(l1) ,reverseList(l2)));
    }
};
