class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> deg(numCourses);
        vector<vector<int>> pars(numCourses);

        for(auto it: prerequisites){
            deg[it[0]]++;
            pars[it[1]].push_back(it[0]);
        }

        queue<int> qu;

        for(int i = 0; i < numCourses; i++){
            if(deg[i] == 0){
                qu.push(i);
            }
        }

        int finished = 0;

        while(!qu.empty()){
            int u = qu.front();
            qu.pop();

            finished++;

            for(int v: pars[u]){
                deg[v]--;

                if(deg[v] == 0){
                    qu.push(v);
                }
            }
        }

        return finished == numCourses;
    }
};