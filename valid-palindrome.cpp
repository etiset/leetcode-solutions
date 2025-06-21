class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;

        while(true){
            while(lo < hi && !isalnum(s[lo])){
                lo++;
            }

            while(lo < hi && !isalnum(s[hi])){
                hi--;
            }

            if(lo >= hi){
                return true;
            }

            if(toupper(s[lo++]) != toupper(s[hi--])){
                return false;
            }
        }

        return true;
    }
};