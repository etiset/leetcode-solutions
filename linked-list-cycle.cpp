/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return false;
        }

        ListNode* fnode = head -> next;
        ListNode* snode = head;

        while(fnode != snode){
            if(fnode -> next == NULL || fnode -> next -> next == NULL){
                return false;
            }

            fnode = fnode -> next -> next;
            snode = snode -> next;
        }

        return true;
    }
};