class Solution {
private:
    int calculateNext(int x){
        int res = 0;

        while(x){
            int r = x % 10;
            x /= 10;

            res += r * r;
        }

        return res;
    }

public:
    bool isHappy(int n) {
        int u = calculateNext(n);
        int v = calculateNext(u);

        while(u != v){
            u = calculateNext(u);
            v = calculateNext(calculateNext(v));

            if(v == 1){
                return true;
            }
        }

        return u == 1;
    }
};