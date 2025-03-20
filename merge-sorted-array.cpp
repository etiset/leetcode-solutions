class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);

        int it = m + n - 1;
        int u = m - 1;
        int v = n - 1;

        while(it != -1){
            if(u == -1){
                nums1[it--] = nums2[v--];
            }

            else if(v == -1){
                nums1[it--] = nums1[u--];
            }

            else{
                if(nums1[u] > nums2[v]){
                    nums1[it--] = nums1[u--];
                }

                else{
                    nums1[it--] = nums2[v--];
                }
            }
        }
    }
};