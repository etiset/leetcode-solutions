class Solution {
private:
    int getValue(const vector<int> &v, int idx){
        if(idx < 0){
            return INT_MIN;
        }

        if(idx >= v.size()){
            return INT_MAX;
        }

        return v[idx];
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        int req = (tot + 1) >> 1;
        int upto = min(req, (int) nums1.size());

        int lo = 0;
        int hi = upto;

        while(lo < hi){
            int l1 = (lo + hi) >> 1;
            int l2 = req - l1;

            if(l2 > nums2.size()){
                lo = l1 + 1;
                continue;
            }

            if(getValue(nums1, l1-1) > getValue(nums2, l2)){
                hi = l1 - 1;
            }

            else if(getValue(nums2, l2-1) > getValue(nums1, l1)){
                lo = l1 + 1;
            }

            else{
                lo = l1;
                break;
            }
        }

        double res = max(getValue(nums1, lo-1), getValue(nums2, req-lo-1));

        if(tot % 2 == 0){
            double nx = min(getValue(nums1, lo), getValue(nums2, req-lo));
            res = (res + nx) / 2.0;
        }

        return res;
    }
};