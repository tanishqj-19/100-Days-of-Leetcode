class Solution {
public:
    ListNode* swapPairs(ListNode* &head) {
        
        // base case
        if(!head || !head->next) return head;

        ListNode* p1 = head, *p2 = head->next;

        p1->next = swapPairs(head->next->next);
        p2->next = p1;

        return p2;
        


    }
};
