class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> digits;
        int carry = 0;

        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size() || carry; j++){
                int k = i + j;

                if(j < num2.size()){
                    carry += (num1[i] - '0') * (num2[j] - '0');
                }

                if(digits.size() == k){
                    digits.push_back(0);
                }

                digits[k] += carry;

                carry = digits[k] / 10;
                digits[k] %= 10;
            }
        }
        
        string res(digits.size(), '0');

        for(int i = 0; i < digits.size(); i++){
            res[digits.size()-1-i] += digits[i];
        }

        return res;
    }
};