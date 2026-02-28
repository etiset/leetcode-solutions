class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){
            return 0;
        }

        bool is_negative = (x < 0);
        x = abs(x);

        int res = 0;

        while(x){
            if(INT_MAX / 10 < res){
                return 0;
            }

            res = 10 * res + (x % 10);
            x /= 10;
        }

        if(is_negative){
            res = -res;
        }

        return res;
    }
};