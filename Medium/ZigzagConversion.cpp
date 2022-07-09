class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        } else {
            string result = "";
            int diagLen = numRows - 2; // val has a range of 0 -> ...
            int vertLen = numRows;
            int stride = vertLen + diagLen;
            int denseColCount = s.size() / stride * 2;
            if ( s.size() % stride > vertLen) {
                denseColCount += 2;
            } else if ( s.size() % stride > 0) {
                denseColCount += 1;
            }
            // iter through rows
            for (int i = 0; i < numRows; i++) {
                // iter through set of verts and diags
                for (int j = 0; j < denseColCount; j++) {
                    if (j % 2 == 0) {
                        // vert case
                        // need to map vert to the linear index.
                        int linearIndex = stride * (j / 2) + i;
                        if (linearIndex < s.size())
                            result += s[linearIndex];
                    } else if (i != 0 && i != (numRows - 1)){
                        // diag case (not on first / last row)
                        // need to map diag to linear index.
                        int linearIndex = stride * (j / 2) + vertLen + diagLen - i;
                        if (linearIndex < s.size())
                            result += s[linearIndex];
                    }
                }   
            }
            return result;
        }
    }
};