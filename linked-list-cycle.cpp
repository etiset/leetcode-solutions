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
        if(!head){
            return false;
        }

        ListNode* u = head;
        ListNode* v = head -> next;

        while(u != v && v != NULL && v -> next != NULL){
            u = u -> next;
            v = v -> next -> next;
        }

        return (u == v);
    }
};