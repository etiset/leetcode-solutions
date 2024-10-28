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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(ListNode* lst: lists){
            if(lst){
                pq.push(make_pair(lst -> val, lst));
            }
        }

        ListNode* res = NULL;
        ListNode* curr = NULL;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            if(res == NULL){
                res = it.second;
                curr = res;
            }

            else{
                curr -> next = it.second;
                curr = curr -> next;
            }

            ListNode* cand = it.second -> next;

            if(cand){
                pq.push(make_pair(cand -> val, cand));
            }
        }

        return res;
    }
};