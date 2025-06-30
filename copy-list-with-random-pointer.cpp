/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        for(Node* hurr = head; hurr; hurr = hurr -> next){
            mp[hurr] = new Node(hurr -> val);
        }
        
        Node* res = nullptr;
        Node* curr = nullptr;
        
        for(Node* hurr = head; hurr; hurr = hurr -> next){
            if(res){
                curr -> next = mp[hurr];
                curr = curr -> next;
            }

            else{
                res = mp[hurr];
                curr = res;
            }

            curr -> random = mp[hurr -> random];
        }

        return res;
    }
};