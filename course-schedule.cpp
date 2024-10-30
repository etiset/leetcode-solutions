class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> deg(numCourses);
        vector<vector<int>> children(numCourses, vector<int>());

        for(auto& it: prerequisites){
            deg[it[0]]++;
            children[it[1]].push_back(it[0]);
        }

        queue<int> qu;
        
        for(int i = 0; i < numCourses; i++){
            if(deg[i] == 0){
                qu.push(i);
            }
        }

        while(!qu.empty()){
            int u = qu.front();
            qu.pop();

            for(int v: children[u]){
                deg[v]--;
                
                if(deg[v] == 0){
                    qu.push(v);
                }
            }
        }

        return std::all_of(deg.begin(), deg.end(), [](int x) {return x == 0;});
    }
};