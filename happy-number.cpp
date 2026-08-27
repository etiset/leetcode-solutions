class Solution {
private:
    int f(int x){
        int res = 0;

        while(x){
            int u = x % 10;
            x /= 10;

            res += u * u;
        }

        return res;
    }

public:
    bool isHappy(int n) {
        int u = f(n);
        int v = f(u);

        while(v != 1){
            if(u == v){
                return false;
            }

            u = f(u);
            v = f(f(v));
        }

        return true;
    }
};