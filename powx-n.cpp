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
            x = 1 / x;
            n = -n;
        }

        double res = 1.0;

        while(n){
            if(n & 1){
                res *= x;
            }

            x *= x;
            n >>= 1;
        }

        return res;
    }
};