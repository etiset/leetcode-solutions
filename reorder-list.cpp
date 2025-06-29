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
private:
    ListNode* findMidNode(ListNode* head){
        ListNode* u = head;
        ListNode* v = head -> next -> next;

        while(v != nullptr){
            u = u -> next;
            v = v -> next;

            if(v == nullptr){
                break;
            }

            v = v -> next;
        }

        return u;
    }

    ListNode* reverseSecondHalf(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            ListNode* nurr = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = nurr;
        }

        return prev;
    }

    void interweaveNodes(ListNode* u, ListNode* v){
        while(v != nullptr){
            ListNode* nu = u -> next;
            ListNode* nv = v -> next;

            u -> next = v;
            v -> next = nu;

            u = nu;
            v = nv;
        }
    }

public:
    void reorderList(ListNode* head) {
        if(head -> next == nullptr || head -> next -> next == nullptr){
            return;
        }

        ListNode* mid = findMidNode(head);
        mid -> next = reverseSecondHalf(mid -> next);
        
        ListNode* head2 = mid -> next;
        mid -> next = NULL;
        interweaveNodes(head, head2);
    }
};