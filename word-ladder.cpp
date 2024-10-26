class Solution {
private:
    bool edgeExists(string& a, string& b){
        int diff = 0;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                diff++;
            }

            if(diff > 1){
                return false;
            }
        }

        return (diff == 1);
    }

    void build_graph(string& beginWord, vector<string>& wordList, vector<vector<int>>& gr){
        for(int i = 0; i < wordList.size(); i++){
            if(edgeExists(beginWord, wordList[i])){
                gr[0].push_back(i + 1);
            }
        }

        for(int i = 0; i < wordList.size(); i++){
            for(int j = i + 1; j < wordList.size(); j++){
                if(edgeExists(wordList[i], wordList[j])){
                    gr[i + 1].push_back(j + 1);
                    gr[j + 1].push_back(i + 1);
              }
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);

        if(it == wordList.end()){
            return 0;
        }

        vector<vector<int>> gr(wordList.size() + 1, vector<int>());
        build_graph(beginWord, wordList, gr);

        vector<int> dist(wordList.size() + 1, 0);
        queue<int> qu;

        dist[0] = 1;
        qu.push(0);

        while(!qu.empty()){
            int fr = qu.front();
            qu.pop();

            for(int nx: gr[fr]){
                if(dist[nx] == 0){
                    dist[nx] = dist[fr] + 1;
                    qu.push(nx);
                }
            }
        }

        int end_index = it - wordList.begin() + 1;

        return dist[end_index];
    }
};