class TrieNode {
private:
    bool is_ending;
    vector<TrieNode*> children;

public:
    TrieNode() {
        is_ending = false;
        children.resize(26, NULL);
    }

    void setIsEnding(bool val){
        is_ending = val;
    }

    bool getIsEnding(){
        return is_ending;
    }

    vector<TrieNode*>& getChildren(){
        return children;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(char c: word){
            int idx = c - 'a';
            vector<TrieNode*>& children = curr -> getChildren();

            if(children[idx] == NULL){
                children[idx] = new TrieNode();
            }

            curr = children[idx];
        }

        curr -> setIsEnding(true);
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char c: word){
            int idx = c - 'a';
            vector<TrieNode*> children = curr -> getChildren();

            if(children[idx] == NULL){
                return false;
            }

            curr = children[idx];
        }
        
        return curr -> getIsEnding();
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char c: prefix){
            int idx = c - 'a';
            vector<TrieNode*> children = curr -> getChildren();

            if(children[idx] == NULL){
                return false;
            }

            curr = children[idx];
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