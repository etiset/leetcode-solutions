class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;

        vector<int> prev(n, INT_MAX);
        vector<int> curr(n, INT_MAX);
        prev[src] = 0;

        while(k--){
            copy(prev.begin(), prev.end(), curr.begin());

            for(auto &flight: flights){
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if(prev[u] < INT_MAX){
                    curr[v] = min(curr[v], prev[u] + w);
                }
            }

            swap(prev, curr);
        }

        return (prev[dst] < INT_MAX) ? prev[dst] : -1;
    }
};