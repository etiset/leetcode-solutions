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
        ListNode* res = NULL;
        ListNode* curr = NULL;

        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL){
                swap(list1, list2);
            }

            else if(list2 != NULL && list1 -> val > list2 -> val){
                swap(list1, list2);
            }

            if(res == NULL){
                res = list1;
                curr = res;
            }

            else{
                curr -> next = list1;
                curr = curr -> next;
            }

            list1 = list1 -> next;
        }

        return res;
    }
};