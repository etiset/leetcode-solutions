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
        if(head -> next == NULL){
            return NULL;
        }

        ListNode* l = head;
        ListNode* r = head;

        while(n--){
            r = r -> next;
        }

        if(r == NULL){
            return head -> next;
        }

        while(r -> next != NULL){
            l = l -> next;
            r = r -> next;
        }

        l -> next = l -> next -> next;

        return head;
    }
};