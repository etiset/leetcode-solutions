class Solution {
private:
    int f(int x){
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
        int u = f(n);
        int v = f(u);

        while(u != v && v != 1){
            u = f(u);
            v = f(f(v));
        }

        return (v == 1);
    }
};