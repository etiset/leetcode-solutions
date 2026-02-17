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
        ListNode* res = nullptr;
        ListNode* curr = nullptr;

        int carry = 0;

        while(carry || l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr){
                carry += l1 -> val;
                l1 = l1 -> next;
            }

            if(l2 != nullptr){
                carry += l2 -> val;
                l2 = l2 -> next;
            }

            int val = carry % 10;
            carry /= 10;

            if(curr != nullptr){
                curr -> next = new ListNode(val);
                curr = curr -> next;
            }

            else{
                res = new ListNode(val);
                curr = res;
            }
        }

        return res;
    }
};