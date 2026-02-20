class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> curr(n, 1);

        while(--m){
            for(int i = 1; i < n; i++){
                curr[i] = curr[i-1] + prev[i];
            }

            swap(prev, curr);
        }

        return prev.back();
    }
};