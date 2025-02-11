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
    ListNode* middleNode(ListNode* head) {
        if(head -> next == NULL){
            return head;
        }

        ListNode* a = head;
        ListNode* b = head -> next;

        while(true){
            a = a -> next;

            if(b -> next == NULL || b -> next -> next == NULL){
                return a;
            }

            b = b -> next -> next;
        }

        return a;
    }
};