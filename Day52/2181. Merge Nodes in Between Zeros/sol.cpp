class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int sum = 0;
        head = head->next;

        while(head){
            if(head->val == 0){
                temp->next = new ListNode(sum);
                sum = 0;
                temp = temp->next;
            }else{
                sum += head->val;
            }

            head = head->next;
        }

        return ans->next;
    }
};
