class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> qu;

        words.insert(beginWord);
        qu.push(make_pair(beginWord, 1));

        while(!qu.empty()){
            auto [word, dis] = qu.front();
            qu.pop();

            for(int i = 0; i < word.size(); i++){
                int val = word[i];

                for(int j = 'a'; j <= 'z'; j++){
                    word[i] = j;

                    if(words.count(word)){
                        if(word == endWord){
                            return dis + 1;
                        }

                        words.erase(word);
                        qu.push(make_pair(word, dis + 1));
                    }
                }

                word[i] = val;
            }
        }

        return 0;
    }
};