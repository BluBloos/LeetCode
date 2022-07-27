class Solution {
    
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int _m = 0;
        int _n = 0;
        
        std::vector<int> r(m + n);
        
        for ( int i = 0; i < m + n; i++ ) {  
            int a = (_m < m) ? nums1[_m] : 1e9 + 1;
            int b = (_n < n) ? nums2[_n] : 1e9 + 1;
            
            if (a < b) {
                r[i] = nums1[_m++];
            }
            else {
                r[i] = nums2[_n++];
            } 
        }
        
        nums1 = r;
        
        return;
    }
};