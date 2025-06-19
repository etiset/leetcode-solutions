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
        auto comp = [](const ListNode* a, const ListNode* b) { return a -> val > b -> val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }

        ListNode* res = NULL;
        ListNode* curr = NULL;

        while(!pq.empty()){
            ListNode* minn = pq.top();
            pq.pop();

            if(res == NULL){
                res = minn;
                curr = res;
            }

            else{
                curr -> next = minn;
                curr = curr -> next;
            }

            if(minn -> next){
                minn = minn -> next;
                pq.push(minn);
            }
        }

        return res;
    }
};