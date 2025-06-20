class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while(lo < hi){
            int m = (lo + hi) >> 1;
            int tot = 0;

            for(int pile: piles){
                tot += (pile + m-1) / m;
            }

            if(tot <= h){
                hi = m;
            }

            else{
                lo = m + 1;
            }
        }

        return lo;
    }
};