class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> curr(n);

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                curr[j] = prev[j];

                if(j > 0){
                    curr[j] += curr[j-1];
                }
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};