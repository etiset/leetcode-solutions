class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MIN){
            double res = 1 / x;

            for(int i = 0; i < 31; i++){
                res *= res;
            }

            return res;
        }

        if(n < 0){
            n = -n;
            x = 1 / x;
        }

        double curr = x;
        double res = 1.0;

        while(n){
            if(n & 1){
                res *= curr;
            }

            curr *= curr;
            n >>= 1;
        }

        return res;
    }
};