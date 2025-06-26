class Solution {
public:
    string minWindow(string s, string t) {
        int dist_occs = 0;
        vector<int> occs(58);

        for(char c: t){
            int idx = c - 'A';
            occs[idx]++;

            if(occs[idx] == 1){
                dist_occs++;
            }
        }

        int st = 0;
        int mst = 0;
        int mlen = INT_MAX;
        
        for(int ed = 0; ed < s.size(); ed++){
            int eidx = s[ed] - 'A';
            occs[eidx]--;

            if(occs[eidx] == 0){
                dist_occs--;
            }

            if(dist_occs == 0){
                while(dist_occs == 0){
                    int clen = ed - st + 1;

                    if(clen < mlen){
                        mst = st;
                        mlen = clen;
                    }

                    int sidx = s[st] - 'A';
                    occs[sidx]++;
                    st++;

                    if(occs[sidx] == 1){
                        dist_occs++;
                    }
                }
            }
        }

        return (mlen == INT_MAX) ? "" : s.substr(mst, mlen);
    }
};