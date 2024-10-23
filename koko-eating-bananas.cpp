class Solution {
private:
    bool isValidSolution(vector<int>& piles, int h, int cand){
        for(int pile: piles){
            int t = (pile + cand - 1) / cand;
            h -= t;

            if(h < 0){
                return false;
            }
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxx = 0;

        for(int pile: piles){
            maxx = max(maxx, pile);
        }

        int lo = 1;
        int hi = maxx;

        while(lo < hi){
            int mid = (lo + hi) / 2;

            if(isValidSolution(piles, h, mid)){
                hi = mid;
            }

            else{
                lo = mid + 1;
            }
        }

        return lo;
    }
};