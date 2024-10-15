class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size());

        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!st.empty()){
                if(temperatures[st.top()] > temperatures[i]){
                    break;
                }

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