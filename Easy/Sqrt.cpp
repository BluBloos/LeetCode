class Solution {
public:
    int mySqrt(int x) {
        // the most stupid thing to do is like, for loop
        // up thru n until you hit the value that is good
        int n = 0;
        while (true) {
            uint64_t sq = (uint64_t )n * n;
            if (sq  > x) {
                return n - 1;
            } else if (sq == x) {
                return n;
            }
            n++;
        }
        return 0;   
    }
    int mySqrt2(int x) {
        // What would be not so stupid?
        // If we computed some sort of mathematical property?
        // So some Googling reveals that we can do some mathematical manipulation + 
        // Newton-Raphson method.
        //
        // Another method that I came up with is to just use a table. There are a reasonable finite 
        // amount of perfect square roots like so: 0 <= x <= 231 - 1.
        // TODO(Noah): implement mySqrt2 to check for speed improvements.
    }
};