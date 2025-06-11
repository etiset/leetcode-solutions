class Solution {
public:
    bool checkValidString(string s) {
        int minn = 0;
        int maxx = 0;

        for(char c: s){
            if(c == '('){
                minn++;
                maxx++;
            }

            else if(c == ')'){
                minn--;
                maxx--;
            }

            else{
                minn--;
                maxx++;
            }

            if(maxx < 0){
                return false;
            }

            minn = max(minn, 0);
        }

        return minn == 0;
    }
};