class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int first_cp = -1, prev_cp = -1;
        int min_dist = INT_MAX;
        int index = 1;
        
        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first_cp == -1) {
                    first_cp = index;
                } else {
                    min_dist = min(min_dist, index - prev_cp);
                }
                prev_cp = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        if (first_cp == prev_cp) return {-1, -1};
        return {min_dist, prev_cp - first_cp};
    }
};
