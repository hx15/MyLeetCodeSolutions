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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* preHead = list1;
        ListNode* postHead;
        ListNode* prepreHead = NULL;
        
        int c = a;
        for(; a >= 1; a--, prepreHead = preHead, preHead = preHead->next);
        
        
        preHead = prepreHead;
        
        
        postHead = list1;
        
        ListNode* next;
        
        int i = 0;
        while(postHead){
            if(i >= c && i <= b ){
                next = postHead->next;
                delete(postHead);
                postHead = next;
            }
            else
                postHead = postHead->next;
            i++;
        }
        
        
        preHead->next = list2;
        
        while(list2->next) list2 = list2->next;
        
        list2->next = next;
        
        return list1;
    }
};
