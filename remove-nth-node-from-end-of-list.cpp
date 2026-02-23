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
        ListNode* res = head;

        while(n--){
            head = head -> next;
        }

        if(head == nullptr){
            return res -> next;
        }

        ListNode* tail = res;

        while(head -> next != nullptr){
            head = head -> next;
            tail = tail -> next;
        }

        tail -> next = tail -> next -> next;

        return res;
    }
};