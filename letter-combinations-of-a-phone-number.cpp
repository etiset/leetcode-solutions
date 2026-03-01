class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> prev = {""};
        vector<string> curr;

        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for(char digit: digits){
            for(auto& word: prev){
                for(char letter: letters[digit - '0']){
                    curr.push_back(word + letter);
                }
            }

            swap(prev, curr);
            curr.clear();
        }

        return prev;
    }
};