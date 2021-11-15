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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next)
            return {-1,-1};
        // so we are treating them alike...
        // the best way to solve this question, is to register localmin, and localmaxs throughout the array, at least their positions as we are iterating, and maybe //min distance could be any point in the localmin, and localmax that we collected, however for max we know it is the farthest one that we have registered.
        vector<int> res (2, -1);
        ListNode* pre = head; 
        int i = 1;
        int first_idx  = -1;
        int last_cpoint = -1;
        int minDistance = INT_MAX;
        for(auto it = head->next ; it != NULL; it = it->next, i++, pre=pre->next ){
            if(it->next == NULL)
                continue;
            if(isMaximaOrMinima(pre, it, it->next)) {
                if(first_idx == -1) {first_idx = i, last_cpoint = i; continue;}
                minDistance = min(minDistance, i - last_cpoint);
                last_cpoint = i;
            }
        }
        if(minDistance != INT_MAX)
            res = {minDistance, last_cpoint - first_idx};
            
        return res;
        
    }
    
    
    
    bool isMaximaOrMinima(ListNode*& pre, ListNode*& curr, ListNode*& next){
        if(pre->val < curr->val && next->val < curr->val)
            return true;
        else if(pre->val > curr->val && next->val > curr->val)
            return true;
        return false;
    }
};
