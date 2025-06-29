class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        int res = 0;
        stack<int> st;
        
        for(int ridx = 0; ridx < heights.size(); ridx++){
            while(!st.empty() && heights[st.top()] > heights[ridx]){
                int idx = st.top();
                st.pop();

                int h = heights[idx];
                int lidx = st.empty() ? 0 : st.top() + 1;
                int w = ridx - lidx;

                res = max(res, h * w);
            }

            st.push(ridx);
        }

        return res;
    }
};