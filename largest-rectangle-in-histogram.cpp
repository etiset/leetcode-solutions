class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;

        stack<int> st;

        for(int i = 0; i < heights.size(); i++){
            int h = heights[i];

            while(!st.empty() && h < heights[st.top()]){
                int cidx = st.top();
                st.pop();

                int nidx = i - 1;
                int pidx = st.empty() ? 0 : st.top() + 1; 
                int w = nidx - pidx + 1;

                res = max(res, heights[cidx] * w);
            }

            st.push(i);
        }

        while(!st.empty()){
            int cidx = st.top();
            st.pop();

            int nidx = heights.size() - 1;
            int pidx = st.empty() ? 0 : st.top() + 1; 
            int w = nidx - pidx + 1;
            
            res = max(res, heights[cidx] * w);
        }

        return res;
    }
};