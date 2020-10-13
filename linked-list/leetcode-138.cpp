#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, int> x;
        unordered_map<int, Node *> y;
        Node *res = new Node(-1);
        Node *p = head, *q = res;
        int cnt = 0;
        while (p)
        {
            q->next = new Node(p->val);
            x[p] = cnt;
            y[cnt] = q->next;
            q = q->next;
            p = p->next;
            cnt++;         
        }
        p = head;
        q = res->next;
        while (p)
        {       
            if (p->random)
                q->random = y[x[p->random]];
            p = p->next;
            q=q->next;
        }
        return res->next;
    }
};
// class Solution {
// public:
//     //方法1
//     Node* copyRandomList(Node* head)
//     {
//         if (head == nullptr)
//             return head;

//         //遍历原链表 创建新链表节点并建立映射关系
//         unordered_map<Node*, Node*> map; //key: 原链表节点  value: 新创建节点 

//         Node* cur = head;
//         while (cur)
//         {
//             map[cur] = new Node(cur->val);
//             cur = cur->next;
//         }

//         //遍历原链表 根据map找新链表的random
//         cur = head;
//         while (cur)
//         {
//             map[cur]->next = map[cur->next];
//             map[cur]->random = map[cur->random];
//             cur = cur->next;
//         }

//         return map[head];
//     }

//     //方法2
//     Node* copyRandomList(Node* head)
//     {
//         if (head == nullptr)
//             return head;

//         //遍历原链表 遍历过程中插入新副本节点
//         Node* cur = head;
//         while (cur)
//         {
//             Node* node = new Node(cur->val);
//             Node* next = cur->next;
//             node->next = next;
//             cur->next = node;
//             cur = next;
//         }

//         //遍历原链表 对新副本节点设置random指针
//         cur = head;
//         while (cur)
//         {
//             cur->next->random = cur->random ? cur->random->next : nullptr;
//             cur = cur->next->next;
//         }

//         //分离出原链表与新副本链表
//         cur = head;
//         Node* new_cur = head->next;
//         Node* res = new_cur;
//         while (cur)
//         {
//             cur->next = cur->next->next;
//             cur = cur->next;

//             new_cur->next = cur ? cur->next : nullptr;
//             new_cur = new_cur->next;
//         }

//         return res; //注意：不能再返回head->next了，head已经是分离后的原链表
//     }
// };
