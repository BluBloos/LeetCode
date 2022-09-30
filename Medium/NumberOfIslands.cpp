class Solution {
public:
    inline int bruteForce(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // can we think of a brute force method for solving?
        // sure: as soon as you hit a 1, do a flood fill outwards.
        // the "visited" arr is embed in the grid, flip the 1s to a 0.
        int numIslands = 0;
        std::vector<std::tuple<int, int>> stack = {}; 
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == '1') {
                    // flood fill out
                    int Y = y;
                    int X = x;
                    stack.push_back(std::make_tuple(Y, X));
                    numIslands++;
                    do {
                        std::tuple<int, int> myTuple = stack.back();
                        Y = std::get<0>(myTuple);
                        X = std::get<1>(myTuple);
                        stack.pop_back();
                        if (grid[Y][X] == '1') {
                            grid[Y][X] = '0';
                            if (Y + 1 < m)
                                stack.push_back(std::make_tuple(Y + 1, X));
                            if (Y - 1 >= 0)
                                stack.push_back(std::make_tuple(Y - 1, X));
                            if (X + 1 < n)
                                stack.push_back(std::make_tuple(Y, X + 1));
                            if (X - 1 >= 0)
                                stack.push_back(std::make_tuple(Y, X - 1));
                        }
                    } while(stack.size() > 0);
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