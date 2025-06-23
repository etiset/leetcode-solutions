struct WordDictionaryNode {
    vector<WordDictionaryNode*> children;
    bool is_end;

    WordDictionaryNode() : children(26, nullptr), is_end(false) {};
};

class WordDictionary {
private:
    WordDictionaryNode* root_;

public:
    WordDictionary() {
        root_ = new WordDictionaryNode();
    }
    
    void addWord(string word) {
        WordDictionaryNode* curr = root_;

        for(char c: word){
            int idx = c - 'a';

            if(curr -> children[idx] == nullptr){
                curr -> children[idx] = new WordDictionaryNode();
            }

            curr = curr -> children[idx];
        }

        curr -> is_end = true;
    }

    bool matchPrefix(const string &word, int widx, WordDictionaryNode* curr){
        for(int i = widx; i < word.size(); i++){
            if(word[i] == '.'){
                for(auto child: curr -> children){
                    if(child && matchPrefix(word, i+1, child)){
                        return true;
                    }
                }

                return false;
            }

            int idx = word[i] - 'a';

            if(curr -> children[idx] == nullptr){
                return false;
            }

            curr = curr -> children[idx];
        }

        return (curr -> is_end);
    }
    
    bool search(string word) {
        return matchPrefix(word, 0, root_);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */