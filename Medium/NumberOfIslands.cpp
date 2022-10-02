typedef struct pair {
    int Y;
    int X;
} pair_t;

class Solution {
public:
    pair_t stack[1024] = {};
    inline int bruteForce(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // can we think of a brute force method for solving?
        // sure: as soon as you hit a 1, do a flood fill outwards.
        // the "visited" arr is embed in the grid, flip the 1s to a 0.
        int numIslands = 0;
        int stackCount = 0;
        //memset(stack, 0, 45000 * sizeof(pair_t));
        //std::vector<pair_t> stack = {};
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == '1') {
                    // flood fill out
                    int Y = y;
                    int X = x;
                    stack[stackCount++] = {Y, X};
                    numIslands++;
                    do {
                        pair_t myPair = stack[stackCount - 1];
                        Y = myPair.Y;
                        X = myPair.X;
                        stackCount--;
                        grid[Y][X] = '0';
                        if (Y + 1 < m && grid[Y + 1][X] == '1')
                            stack[stackCount++] = {(Y + 1), X};
                        if (Y - 1 >= 0 && grid[Y - 1][X] == '1')
                            stack[stackCount++] = {(Y - 1), X};
                        if (X + 1 < n && grid[Y][X + 1] == '1')
                            stack[stackCount++] = {Y, (X + 1)};
                        if (X - 1 >= 0 && grid[Y][X - 1] == '1')
                            stack[stackCount++] = {Y, (X - 1)};
                    } while(stackCount > 0);
                }
            }
        }
        return numIslands;
    }
    int numIslands(vector<vector<char>>& grid) {       
#if 1 
        return bruteForce(grid);
#endif
    }
};