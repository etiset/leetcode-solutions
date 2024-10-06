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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* curr = NULL;

        while(list1 != NULL || list2 != NULL){
            ListNode* cand = list1;

            if(list1 == NULL || (list2 != NULL && list2 -> val < list1 -> val)){
                swap(list1, list2);
            }

            if(head == NULL){
                head = list1;
                curr = list1;

                list1 = list1 -> next;
                continue;
            }

            curr -> next = list1;
            curr = curr -> next;

            list1 = list1 -> next;
        }

        return head;
    }
};