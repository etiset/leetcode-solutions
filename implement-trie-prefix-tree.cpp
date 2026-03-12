struct TrieNode {
    vector<TrieNode*> children_ {vector<TrieNode*>(26, nullptr)};
    bool is_end_ {false};
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

            if(curr -> children_[idx] == nullptr){
                curr -> children_[idx] = new TrieNode();
            }

            curr = curr -> children_[idx];
        }

        curr -> is_end_ = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root_;
        
        for(char c: word){
            int idx = c - 'a';

            if(curr -> children_[idx] == nullptr){
                return false;
            }

            curr = curr -> children_[idx];
        }

        return curr -> is_end_;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root_;
        
        for(char c: prefix){
            int idx = c - 'a';

            if(curr -> children_[idx] == nullptr){
                return false;
            }

            curr = curr -> children_[idx];
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