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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fake_head = new ListNode(-1, head);
        ListNode* lptr = fake_head;
        ListNode* rptr = fake_head;

        for(int i = 0; i < n; i++){
            rptr = rptr -> next;
        }

        while(rptr -> next != NULL){
            lptr = lptr -> next;
            rptr = rptr -> next;
        }

        if(n == 1){
            if(head -> next == NULL){
                delete fake_head;

                return NULL;
            }

            delete fake_head;
            delete lptr -> next;
            lptr -> next = NULL;

            return head;
        }

        ListNode* to_delete = lptr -> next;
        lptr -> next = lptr -> next -> next;
        ListNode* res = fake_head -> next;

        delete to_delete;
        delete fake_head;
        
        return res;
    }
};