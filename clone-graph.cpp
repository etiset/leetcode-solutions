/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }

        Node* res = new Node(node -> val);

        unordered_map<Node*, Node*> node_map;
        queue<Node*> qu;
        
        node_map[node] = res;
        qu.push(node);

        while(!qu.empty()){
            auto u = qu.front();
            qu.pop();

            Node* nu = node_map[u];

            for(Node* v: u -> neighbors){
                if(node_map.count(v) == 0){
                    node_map[v] = new Node(v -> val);
                    qu.push(v);
                }

                Node* nv = node_map[v];
                nu -> neighbors.push_back(nv);
            }
        }

        return res;
    }
};