class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> res;

        for(int i = 0; i < num1.size(); i++){
            int carry = 0;

            for(int j = 0; j < num2.size(); j++){
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int to_add = prod + carry;

                int idx = i + j;

                if(idx >= res.size()){
                    res.push_back(0);
                }

                int val = to_add + res[idx];
                res[idx] = val % 10;
                carry = val / 10;
            }

            int idx = i + num2.size();

            while(carry > 0){
                if(idx >= res.size()){
                    res.push_back(0);
                }

                int val = carry + res[idx];
                res[idx] = val % 10;
                carry = val / 10;

                idx++;
            }
        }

        string res_str = "";
        bool leading_zero = true;

        while(res.size() > 0){
            if(res.back() != 0){
                leading_zero = false;
            }

            if(!leading_zero){
                res_str += to_string(res.back());
            }
            
            res.pop_back();
        }

        if(leading_zero){
            return "0";
        }

        return res_str;
    }
};