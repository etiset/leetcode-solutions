class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> gr(n, vector<pair<int, int>>());

        for(auto& it: times){
            gr[it[0]-1].push_back({it[1]-1, it[2]});
        }

        int maxx = 105 * 6005;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<int> dists(n, maxx);

        pq.push({0, k-1});
        dists[k-1] = 0;

        while(!pq.empty()){
            auto [ucost, u] = pq.top();
            pq.pop();

            if(ucost > dists[u]){
                continue;
            }
            
            for(auto& [v, w]: gr[u]){
                int vcost = ucost + w;

                if(vcost < dists[v]){
                    pq.push({vcost, v});
                    dists[v] = vcost;
                }
            }
        }

        if(any_of(dists.begin(), dists.end(), [maxx](int x) {return x == maxx;})){
            return -1;
        }

        return *max_element(dists.begin(), dists.end());
    }
};