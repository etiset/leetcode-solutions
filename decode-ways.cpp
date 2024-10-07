class Solution {
private:
    int isValidDecoding(string& s, int st, int len){
        if(s[st] == '0'){
            return 0;
        }

        if(len == 1){
            return 1;
        }

        int val = 10*(s[st]-'0') + (s[st+1]-'0');

        return (1 <= val && val <= 26);
    }
public:
    int numDecodings(string s) {
        int prev1 = 0;
        int prev2 = 0;

        if(s.size() >= 1){
            prev1 = isValidDecoding(s, s.size()-1, 1);
        }

        if(s.size() >= 2){
            prev2 = prev1;
            prev1 = isValidDecoding(s, s.size()-2, 2);

            if(isValidDecoding(s, s.size()-2, 1) && isValidDecoding(s, s.size()-1, 1)){
                prev1++;
            }
        }

        for(int i = s.size()-3; i >= 0; i--){
            int curr = 0;

            if(isValidDecoding(s, i, 2)){
                curr += prev2;
            }

            if(isValidDecoding(s, i, 1)){
                curr += prev1;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};