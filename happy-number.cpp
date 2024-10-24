class Solution {
private:
    int calculateNext(int n){
        int res = 0;
        
        while(n){
            res += (n % 10) * (n % 10);
            n /= 10;
        }

        return res;
    }

public:
    bool isHappy(int n) {
        int u = n;
        int v = calculateNext(n);
        
        while(u != v){
            u = calculateNext(u);
            v = calculateNext(calculateNext(v));

            if(v == 1){
                return true;
            }
        }

        return (v == 1);
    }
};