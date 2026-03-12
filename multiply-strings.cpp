class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int carry = 0;
        vector<int> prod;
        
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size() || carry; j++){
                int idx = i + j;

                if(idx == prod.size()){
                    prod.push_back(0);
                }

                if(j < num2.size()){
                    prod[idx] += (num1[i] - '0') * (num2[j] - '0');
                }

                if(carry){
                    prod[idx] += carry;
                }

                carry = prod[idx] / 10;
                prod[idx] %= 10;
            }
        }

        string res(prod.size(), '0');

        for(int i = 0; i < prod.size(); i++){
            res[i] += prod[prod.size() - 1 - i];
        }

        return res;
    }
};