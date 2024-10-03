class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* it = res;

        int carry = 0;

        while(l1 != NULL || l2 != NULL){
            int curr = carry;

            if(l1 != NULL){
                curr += l1 -> val;
                l1 = l1 -> next;
            }

            if(l2 != NULL){
                curr += l2 -> val;
                l2 = l2 -> next;
            }

            it -> val = curr % 10;
            carry = curr / 10;

            if(carry || l1 != NULL || l2 != NULL){
                it -> next = new ListNode();
                it = it -> next;
            }
        }

        if(carry){
            it -> val = 1;
        }

        return res;
    }
};