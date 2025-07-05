class Solution {
private:
    int find_set(vector<int> &par, int u){
        if(u == par[u]){
            return u;
        }

        return par[u] = find_set(par, par[u]);
    }

    bool unite_sets(vector<int> &par, vector<int> &sz, int u, int v){
        int paru = find_set(par, u);
        int parv = find_set(par, v);

        if(paru != parv){
            if(sz[paru] < sz[parv]){
                swap(paru, parv);
            }

            par[parv] = paru;
            sz[paru] += sz[parv];

            return false;
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n);
        vector<int> sz(n, 1);

        for(int i = 0; i < n; i++){
            par[i] = i;
        }

        for(const auto &edge: edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            if(unite_sets(par, sz, u, v)){
                return edge;
            }
        }

        return {-1, -1};
    }
};
