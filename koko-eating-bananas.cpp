class Solution {
private:
    int calculateTime(int k, vector<int>& piles){
        int res = 0;

        for(int pile: piles){
            res += (pile + k-1) / k;
        }

        return res;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int ed = *max_element(piles.begin(), piles.end());

        while(st < ed){
            int m = (st + ed) / 2;
            int time_required = calculateTime(m, piles);

            if(time_required <= h){
                ed = m;
            }

            else{
                st = m + 1;
            }
        }

        return st;
    }
};