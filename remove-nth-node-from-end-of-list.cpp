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
        ListNode* st = head;
        ListNode* ed = head;

        while(n--){
            ed = ed -> next;
        }

        if(ed == nullptr){
            return head -> next;
        }

        while(ed -> next != nullptr){
            st = st -> next;
            ed = ed -> next;
        }

        st -> next = st -> next -> next;
        
        return head;
    }
};