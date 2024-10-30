class Solution {
private:
    int find_set(int u, vector<int>& parents){
        if(u == parents[u]){
            return u;
        }

        return parents[u] = find_set(parents[u], parents);
    }

    bool unite_sets(int u, int v, vector<int>& parents, vector<int>& sizes){
        int pu = find_set(u, parents);
        int pv = find_set(v, parents);

        if(pu != pv){
            if(sizes[pu] < sizes[pv]){
                swap(pu, pv);
            }

            parents[pv] = pu;
            sizes[pu] += sizes[pv];

            return false;
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n);
        vector<int> sizes(n);

        for(int i = 0; i < n; i++){
            parents[i] = i;
            sizes[i] = 1;
        }

        for(auto& edge: edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            if(unite_sets(u, v, parents, sizes)){
                return edge;
            }
        }

        return {-1, -1};
    }
};