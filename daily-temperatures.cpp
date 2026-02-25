class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> st;

        for(int i = temperatures.size()-1; i >= 0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                res[i] = st.top() - i;
            }

            st.push(i);
        }

        return res;
    }
};