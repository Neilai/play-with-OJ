class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        if(!node->next){
        	node=NULL;
        	return;
        }
        node->val=node->next->val;
        node->next=node->next->next;
    }
};