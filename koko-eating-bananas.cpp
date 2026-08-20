class Solution {
private:
    bool canEat(vector<int>& piles, int h, int b){
        for(int pile: piles){
            int t = (pile + b - 1) / b;
            h -= t;
            
            if(h < 0){
                return false;
            }
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int ed = 1000000000;

        while(st < ed){
            int m = (st + ed) / 2;

            if(canEat(piles, h, m)){
                ed = m;
            }

            else{
                st = m + 1;
            }
        }

        return st;
    }
};