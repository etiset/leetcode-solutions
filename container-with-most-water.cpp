class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int ans = 0;

        while(l < r){
            int w = r - l;

            if(height[l] <= height[r]){
                ans = max(ans, w * height[l]);
                l++;
            }

            else{
                ans = max(ans, w * height[r]);
                r--;
            }
        }

        return ans;
    }
};