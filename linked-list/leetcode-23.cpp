#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode header(-1);
        ListNode* p = &header;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        p->next = l1 == NULL ? l2 : l1;
        return header.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int L, int R) {
        if (L == R) return lists[L];
        if (R < L) return nullptr;
        int mid = (L + R) / 2;
        return mergeTwoLists(mergeKLists(lists, L, mid),
                             mergeKLists(lists, mid + 1, R));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};