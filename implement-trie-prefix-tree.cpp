struct TrieNode {
    vector<TrieNode*> children {vector<TrieNode*>(26, nullptr)};
    bool is_end {false};
};

class Trie {
private:
    TrieNode* root_;

public:
    Trie() {
        root_ = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root_;

        for(char c: word){
            int idx = c - 'a';

            if(curr -> children[idx] == nullptr){
                curr -> children[idx] = new TrieNode();
            }

            curr = curr -> children[idx];
        }

        curr -> is_end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root_;

        for(char c: word){
            int idx = c - 'a';

            if(curr -> children[idx] == nullptr){
                return false;
            }

            curr = curr -> children[idx];
        }

        return curr -> is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root_;

        for(char c: prefix){
            int idx = c - 'a';

            if(curr -> children[idx] == nullptr){
                return false;
            }

            curr = curr -> children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */