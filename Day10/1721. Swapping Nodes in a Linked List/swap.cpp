class Solution {
public:
    ListNode* swapNodes(ListNode* &head, int &k) {
        ListNode* n1 = head, *n2 = nullptr;
        
        for(auto i = head; i != nullptr; i = i->next){
            if(n2) n2 = n2->next;
            if(--k == 0){
                n1 = i;
                n2 = head;
            }
        }
        swap(n1->val, n2->val);

        
        return head;
    }
};
