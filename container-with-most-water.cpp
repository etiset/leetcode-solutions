class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;

        int st = 0;
        int ed = height.size() - 1;

        while(st < ed){
            int cand = (ed - st) * min(height[ed], height[st]);
            res = max(res, cand);

            if(height[st] < height[ed]){
                st++;
            }

            else{
                ed--;
            }
        }

        return res;
    }
};