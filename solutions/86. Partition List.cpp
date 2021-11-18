/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(!head)
            return NULL;
        
        ListNode* b_sentinel = new ListNode(0);
        ListNode* s_sentinel = new ListNode(0);
        ListNode* s = s_sentinel;
        ListNode* b = b_sentinel;
        
        while(head){
            ListNode* next = head->next;
            addNode(s, b, head, x);           
            head = next;
        }
        ListNode* res; 
        if(b_sentinel->next && s_sentinel->next) {
            s->next = b_sentinel->next;
            res = s_sentinel->next;   
        }
        else if(b_sentinel->next && !s_sentinel->next)
            res = b_sentinel->next;
        else
            res = s_sentinel->next;
        
        return res;
        
        
        
    }
    
    void addNode(ListNode*& s, ListNode*& b, ListNode*& node, int x){
        if(!node) return;
        if(node->val < x){
            s->next = node;
            s = s->next;
        }
        if(node->val >= x) {
            b->next = node;
            b = b->next;
        }
        ListNode* nxt = node->next;
        node->next = NULL;
        node = nxt;
    }
};
