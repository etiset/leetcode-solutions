class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> curr(n);

        for(int i = 1; i < m; i++){
            curr[0] = prev[0];

            for(int j = 1; j < n; j++){
                curr[j] = curr[j-1] + prev[j];
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};