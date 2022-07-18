class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // we want to probably do a binary search.
        // and like, that's it, right?
        int mi = nums.size() / 2;
        int a = 0; // lower bound
        int b = nums.size() - 1; // upper bound
        for (; true; ) {
            if ( nums[mi] == target ) {
                return mi;
            } else if ( nums[mi] > target ) {
                // left search
                b = mi - 1;
            } else {
                a = mi + 1;                
            }
            
            if (a > b) {
                return (a > mi) ? mi + 1 : mi;
            }
            
            // new middle index
            mi = a + (b - a + 1) / 2;
        }
    }
};