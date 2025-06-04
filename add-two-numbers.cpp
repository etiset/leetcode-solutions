/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* curr = NULL;

        int carry = 0;

        while(carry || l1 != NULL || l2 != NULL){
            int val = carry;
            carry = 0;

            if(l1 != NULL){
                val += l1 -> val;
                l1 = l1 -> next;
            }

            if(l2 != NULL){
                val += l2 -> val;
                l2 = l2 -> next;
            }

            carry = val / 10;
            val %= 10;

            if(res == NULL){
                res = new ListNode(val);
                curr = res;
            }

            else{
                curr -> next = new ListNode(val);
                curr = curr -> next; 
            }
        }

        return res;
    }
};