class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> res;

        while(!qu.empty()){
            int u = qu.front();
            qu.pop();

            res.push_back(u);

            for(int v: children[u]){
                deg[v]--;
                
                if(deg[v] == 0){
                    qu.push(v);
                }
            }
        }

        if(res.size() == numCourses){
            return res;
        }

        return {};
    }
};