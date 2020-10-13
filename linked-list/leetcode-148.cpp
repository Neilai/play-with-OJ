#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2, int L, int R)
    {
        cout<<l1->val<<" "<<l2->val<<endl;
        cout<<"L "<<L<<"R "<<R<<endl;
        ListNode *p1 = l1, *p2 = l2;
        ListNode header(-1);
        ListNode *p3 = &header;
        int cnt1 = 0, cnt2 = 0;
        while (cnt1 < L || cnt2 < R)
        {
            if (cnt1 == L)
            {
                p3->next = p2;
                p2 = p2->next;
                cnt2++;
            }
            else if (cnt2 == R)
            {
                p3->next = p1;
                p1 = p1->next;
                cnt1++;
            }
            else if (p1->val < p2->val)
            {
                p3->next = p1;
                p1 = p1->next;
                cnt1++;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
                cnt2++;
            }
            cout<<"cnt1: "<<cnt1<<"cnt2: "<<cnt2<<endl;
            p3 = p3->next;
        }
        p3->next=nullptr;
        return header.next;
    }
   ListNode *sort(ListNode *left, int len)
    {
        if(!len) return nullptr;
        if(len==1) return left;
        int cnt = 0;
        ListNode *right = left;
        while (cnt < len / 2)
        {
            cnt++;
            right = right->next;
        }       
        return merge( sort(left, len / 2),  sort(right, len - len / 2), len / 2, len - len / 2);
    };

    ListNode *sortList(ListNode *head)
    {
        int len = 0;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            len++;
        }
        return sort(head, len);
    }
};


// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if (head == NULL || head->next == NULL)
//         {
//             return head;
//         }
//         ListNode* pmid;
//         ListNode* mid = head;
//         ListNode* trail = head;
//         while (trail && trail->next)
//         {
//             pmid = mid;
//             mid = mid->next;
//             trail = trail->next->next;
//         }
//         pmid->next = NULL;

//         return twoWayMerge(sortList(head), sortList(mid));
//     }

//     ListNode* twoWayMerge(ListNode* l1, ListNode* l2) {
//         ListNode header(-1);
//         ListNode *p = &header;
//         while (l1 && l2)
//         {
//             if (l1->val < l2->val)
//             {
//                 p->next = l1;
//                 l1 = l1->next;
//             }
//             else
//             {
//                 p->next = l2;
//                 l2 = l2->next;
//             }
//             p = p->next;
//         }

//         p->next = l1 == NULL ? l2 : l1;

//         return header.next;
//     }
// };

