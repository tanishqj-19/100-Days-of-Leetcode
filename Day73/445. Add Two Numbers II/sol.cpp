class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *prev = NULL, *next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* &l1, ListNode* &l2) {
        ListNode* head1 = reverse(l1), *head2 = reverse(l2);

        ListNode* head3 = new ListNode(0);
        ListNode* temp = head3;

        int c = 0;

        while(head1 || head2 || c){

            if(head1){
                c += head1->val;
                head1 = head1->next;
            }

            if(head2){
                c += head2->val;
                head2 = head2->next;
            }

            ListNode* node = new ListNode(c % 10);
            temp->next = node;
            temp = temp->next; 
            c /= 10;
        }

        return reverse(head3->next);
    }
};
