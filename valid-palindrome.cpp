class Solution {
    int findKthAlnum(string& s, int k){
        int cnt = -1;

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                cnt++;
            }

            if(cnt == k){
                return i;
            }
        }

        return -1;
    }

public:
    bool isPalindrome(string s) {
        int cnt = 0;

        for(char c: s){
            if(isalnum(c)){
                cnt++;
            }
        }

        if(cnt == 0){
            return true;
        }

        int i = findKthAlnum(s, (cnt&1) ? cnt/2 : cnt/2-1);
        int j = findKthAlnum(s, (cnt&1) ? cnt/2 : cnt/2);

        while(i >= 0 && j < s.size()){
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }

            while(--i >= 0 && !isalnum(s[i]));
            while(++j < s.size() && !isalnum(s[j]));
        }

        return true;
    }
};