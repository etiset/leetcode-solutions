class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MIN){
            for(int i = 0; i < 31; i++){
                x *= x;
            }

            return 1.0 / x;
        }

        bool invert_res = false;

        if(n < 0){
            n = -n;
            invert_res = true;
        }

        double res = 1.0;
        double curr = 1.0;

        while(n){
            if(n & 1){
                res *= x;
            }

            x *= x;
            n >>= 1;
        }

        if(invert_res){
            res = 1.0 / res;
        }

        return res;
    }
};