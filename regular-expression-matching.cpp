class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> poss(m+1, vector<bool>(n+1));
        poss[0][0] = true;

        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '*'){
                    poss[i][j] = poss[i][j-2];

                    if(i > 0){
                        bool cond1 = s[i-1] == p[j-2] || p[j-2] == '.';
                        bool cond2 = poss[i-1][j];
                        
                        poss[i][j] = poss[i][j] || (cond1 && cond2);
                    }

                    continue;
                }

                if(i > 0){
                    bool cond1 = s[i-1] == p[j-1] || p[j-1] == '.';
                    bool cond2 = poss[i-1][j-1];
                    
                    poss[i][j] = cond1 && cond2;
                }

            }
        }

        return poss[m][n];
    }
};