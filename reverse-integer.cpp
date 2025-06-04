class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){
            return 0;
        }

        int res = 0;
        int s = (x < 0) ? -1 : 1;
        x *= s;

        while(x){
            int r = x % 10;
            if((INT_MAX - r) / 10 < res){
                return 0;
            }

            res = 10 * res + r;
            x /= 10;
        }

        return s * res;
    }
};