class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }

        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> prev = {""};
        vector<string> curr;

        for(char c: digits){
            curr.clear();

            for(string word: prev){
                for(char x: letters[c - '0']){
                    curr.push_back(word + x);
                }
            }

            swap(prev, curr);
        }

        return prev;
    }
};