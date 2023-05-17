class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* curr = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            curr = curr->next;
        }

        ListNode* next , *prev = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        int sum = 0;
        while(prev){
            sum = max(sum, prev->val + head->val);
            prev = prev->next; head = head->next;
        }

        return sum;
    }
};
