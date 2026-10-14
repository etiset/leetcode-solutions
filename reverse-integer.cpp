class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){
            return 0;
        }

        int sgn = (x < 0) ? -1 : 1;
        x *= sgn;

        int val = 0;
        int ubnd = INT_MAX / 10;

        while(x){
            if(val > ubnd){
                return 0;
            }

            val = 10 * val + (x % 10);
            x /= 10;
        }

        return sgn * val;
    }
};