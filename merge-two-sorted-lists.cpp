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
        ListNode* res = nullptr;
        ListNode* curr = nullptr;

        while(list1 != nullptr || list2 != nullptr){
            if(list1 == nullptr){
                swap(list1, list2);
            }

            if(list2 != nullptr && list1 -> val > list2 -> val){
                swap(list1, list2);
            }

            if(curr != nullptr){
                curr -> next = list1;
                
                curr = curr -> next;
                list1 = list1 -> next;
            }

            else{
                res = list1;
                curr = list1;

                list1 = list1 -> next;
            }
        }

        return res;
    }
};