class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int ed = s.size() - 1;

        while(st < ed){
            while(st < ed && !isalnum(s[st])){
                st++;
            }

            while(st < ed && !isalnum(s[ed])){
                ed--;
            }

            if(tolower(s[st]) != tolower(s[ed])){
                return false;
            }

            st++;
            ed--;
        }

        return true;
    }
};