class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }

        vector<string> digit2letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        queue<pair<string, int>> qu;
        qu.push(make_pair("", 0));

        while(qu.front().second != digits.size()){
            pair<string, int> fr = qu.front();
            qu.pop();

            int digit = int(digits[fr.second]) - 48;

            for(char letter: digit2letters[digit]){
                string nf = fr.first + letter;
                int ns = fr.second + 1;
                qu.push(make_pair(nf, ns));
            }
        }

        vector<string> res;

        while(!qu.empty()){
            res.push_back(qu.front().first);
            qu.pop();
        }

        return res;
    }
};