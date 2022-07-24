class Solution {
    int cache[46] = {0};
public:
    int climbStairs(int n) {
        // return climbStairs2(n); 
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            int n1 = (cache[n-1] == 0) ? cache[n-1] = climbStairs(n-1) : cache[n-1];
            int n2 = (cache[n-2] == 0) ? cache[n-2] = climbStairs(n-2) : cache[n-2];
            return n1 + n2;
        }    
    }
};