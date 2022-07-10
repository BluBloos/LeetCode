// TODO(Noah): Need to make faster as exceeding the time-limit on 
// Leetcode.
// We anticpate that we can win by saving state about groups of three!
class Solution {
public:
    string searchFunc(const string &s, int index, int index2) {
        // even case search is special because we need to first validate that 
        // this even case is even valid.
        if (s[index] != s[index2]) {
            return s.substr(index2, 1);
        }
        int sLen = s.size(); int i;
        for (i = 1; true; i++) {
            if (index - i < 0) break;
            if (index2 + i == sLen) break;
            char leftChar = s[index - i];
            char rightChar = s[index2 + i];
            if (leftChar != rightChar) {
                // mismatch. return current substr.
                return s.substr(index - (i - 1), 2 + 2 * (i - 1));
            }
        }
        return s.substr( index - (i - 1), 2 + 2 * (i - 1) ); // never hit the mismatch case. 
    }
    // odd case
    string searchFunc(const string &s, int index) {
        int sLen = s.size();
        int i;
        for (i = 1; true; i++) {
            if (index - i < 0) break;
            if (index + i == sLen) break;
            char leftChar = s[index - i];
            char rightChar = s[index + i];
            if (leftChar != rightChar) {
                // mismatch. return current substr.
                return s.substr(index - (i - 1), 1 + 2 * (i - 1));
            }
        }
        return s.substr( index - (i - 1), 1 + 2 * (i - 1) ); // never hit the mismatch case.
    }
    string longestPalindrome(string s) {   
        int len = s.size();
        string result = ""; // Current highest match.
        int maxPosLen = len; // What we know is possible.
        int mi = len / 2;
        std::vector<int> indices;
        indices.push_back(mi); // this if built up over the for loop
        bool indDir = (len % 2 == 0);
        int indicesLeft = mi;
        int indicesRight = mi;
        for (int maxPosLen = len; maxPosLen >= 1; maxPosLen--) {        
            if (maxPosLen == result.size()) {
                break; // fell onto the lower-bound.
            }
            for (int j = 0; j < indices.size(); j++) {
                string _s;
                if (maxPosLen % 2 == 0) {
                    // TODO: Make the algo faster by saving state about groups of three and groups of two.
                    _s = searchFunc(s, indices[j] - 1, indices[j]);
                } else {
                    _s = searchFunc(s, indices[j]);
                }
                int _sLen = _s.size();
                if (_sLen == len) { return _s; } 
                else if (_sLen > result.size()) {
                    result = _s; // collapse the lower-bound.
                }
            }
            // add index to list of indices
            if (indDir) {
                indices.push_back( --indicesLeft );
            } else {
                indices.push_back( ++indicesRight );
            }
            indDir = !indDir;  
        }
        return result;
    }
};