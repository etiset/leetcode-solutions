class Solution {
private:
    int findParent(vector<int>& par, int u){
        if(u == par[u]){
            return u;
        }

        return par[u] = findParent(par, par[u]);
    }

    void uniteSets(vector<int>& par, vector<int>& sz, int u, int v){
        int paru = findParent(par, u);
        int parv = findParent(par, v);

        if(paru != parv){
            if(sz[paru] < sz[parv]){
                swap(paru, parv);
            }

            par[parv] = paru;
            sz[paru] += sz[parv];
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> par(n);
        vector<int> sz(n, 1);

        iota(par.begin(), par.end(), 0);

        for(auto& edge: edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            if(findParent(par, u) == findParent(par, v)){
                return edge;
            }

            uniteSets(par, sz, u, v);
        }

        return {-1, -1};
    }
};