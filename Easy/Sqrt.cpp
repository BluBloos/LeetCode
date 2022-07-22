class Solution {
    //std::vector<int> pSquares = {};
    //bool init = false;        
public:
    int mySqrt(int x) {
        // we want to probably do a binary search.
        // and like, that's it, right?
        int mi = (46340 + 1) / 2;
        int a = 0; // lower bound
        int b = (46340 + 1) - 1; // upper bound
        for (; true; ) {
            if ( mi * mi == x ) {
                return mi;
            } else if ( mi * mi > x ) {
                // left search
                b = mi - 1;
            } else {
                a = mi + 1;                
            }
            if (a > b) {
                return (a > mi) ? mi: mi - 1;
            }
            // new middle index
            mi = a + (b - a + 1) / 2;
        }
    }
};