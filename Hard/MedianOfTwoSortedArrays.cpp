// This is a leetcode hard problem???
/*
    That's my first take at this.
    The easy solution to see here is that we go through both array, but iteration
    one value at a time for each of the arrays.

    obviously, you want to do this merging step...
    but like, there is no need to store any memory.
    we can just figure out what the index is up font
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i1 = (m + n) / 2;
        int i2 = i1 - 1;
        // handle the even and odd cases
        if ( (m + n) % 2 == 0) {} else {
            i2 = i1; // no different for case where we can just take middle of array.
        }
        short i = 0;
        short j = 0;
        int buffer[2];
        for (short k = 0; k < m + n; k++) {
            // current values considering i and j bounds.
            int num1 = (i < m) ? nums1[i] : 10000000;
            int num2 = (j < n) ? nums2[j] : 10000000;
            // determine current k value.            
            if ( num1 < num2 ) {
                buffer[0] = nums1[i];
                i++;
            } else {
                buffer[0] = nums2[j];
                j++;
            }
            if (k == i2) {
                buffer[1] = buffer[0]; 
            }
            if (k == i1) {
                return (buffer[0] + buffer[1]) / 2.0f;
            }   
        }
        return 0; // SHOULD NEVER GET HERE.   
    }
};