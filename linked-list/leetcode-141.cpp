#include <unordered_map>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         unordered_map<ListNode *, bool> m;
//         while (head)
//         {
//             if (m[head])
//                 return true;
//             else
//                 m[head] = true;
//             head = head->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr) {
            if(!fast->next)  return false;
            slow = slow->next;
            fast = fast->next->next;        
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};
