class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        
        for(int idx = n+m-1; idx >=0; idx--){
            if((i>=0 && j>=0 && nums1[i] < nums2[j]) || i < 0)
                nums1[idx] = nums2[j--];
            else
                nums1[idx] = nums1[i--];
        }
    }
};