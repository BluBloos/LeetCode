// NOTE(Noah): The algo could be simplified below. I solved this without reading any solutions before, 
// or studying any techniques of how to do this. I simply looked at the problem and tried to come up 
// with an algo for solving it.
//
// after now reading the solutions, my solution is most similar to the Expand Around Center 
// method.
//
// Which one is faster? Who knows ... wouldn't it be a fun exercise to find the answer?
typedef struct sc {
    short maxThree;
    short maxTwo;
} sc_t;
class Solution {
    int indices[1000];
    sc_t cache[1000];
public:
    // even cases.
    inline 
    string buildPalindrome(const string &s, int index, int index2, int len) {
        // index and index2 are middle of palindrome, and len is total len (including middle).
        return s.substr(index - (len - 2) / 2, len);
    }
    inline
    int searchFunc(const string &s, int index, int index2) {
        // even case search is special because we need to first validate that 
        // this even case is even valid.
        if (s[index] != s[index2]) {
            return 1;
        }
        int sLen = s.size(); int i;
        for (i = 1; true; i++) {
            if (index - i < 0) break;
            if (index2 + i == sLen) break;
            char leftChar = s[index - i];
            char rightChar = s[index2 + i];
            if (leftChar != rightChar) {
                // mismatch.
                break;
            }
        }
        return 2 + 2 * (i - 1);
    }
    // odd cases
    inline 
    string buildPalindrome(const string &s, int index, int len) {
        // index is middle of palindrome, and len is total len.
        return s.substr(index - (len - 1) / 2, len);
    }
    inline 
    int searchFunc(const string &s, int index) {
        int sLen = s.size();
        int i;
        for (i = 1; true; i++) {
            if (index - i < 0) break;
            if (index + i == sLen) break;
            char leftChar = s[index - i];
            char rightChar = s[index + i];
            if (leftChar != rightChar) {
                break;
            }
        }
        return 1 + 2 * (i - 1);
    }
    // algo
    string longestPalindrome(string s) {  
        int len = s.size();
        int maxPosLen = len; // What we know is possible.
        int mi = len / 2;
        memset(cache, 0, sizeof(cache));
        memset(indices, 0, sizeof(indices));
        int indInd = 0;
        indices[indInd++] = mi; // this if built up over the for loop
        bool indDir = (len % 2 == 0);
        int indicesLeft = mi;
        int indicesRight = mi;
        for (int maxPosLen = len; maxPosLen >= 1; maxPosLen--) {        
            for (int j = 0; j < indInd; j++) {
                int _sLen;
                if (maxPosLen % 2 == 0) {
                    if (cache[indices[j]].maxTwo == 0) {
                        _sLen = searchFunc(s, indices[j] - 1, indices[j]);
                        cache[indices[j]].maxTwo = _sLen;
                    } else {
                        _sLen = cache[indices[j]].maxTwo;
                    }
                } else {
                    if (cache[indices[j]].maxThree == 0) {
                        _sLen = searchFunc(s, indices[j]);
                        cache[indices[j]].maxThree = _sLen;
                    } else {
                      
                        _sLen = cache[indices[j]].maxThree;
                    }
                }
                if (_sLen == maxPosLen) { 
                    return  (maxPosLen % 2 == 0) ? 
                                buildPalindrome(s, indices[j] - 1, indices[j], maxPosLen) :
                                buildPalindrome(s, indices[j], maxPosLen); 
                }
            }
            // add index to list of indices
            if (indDir) {
                indices[indInd++] = --indicesLeft;
            } else {
                indices[indInd++] = ++indicesRight;
            }
            indDir = !indDir;  
        }
        return ""; // should never reach this case.
    }
};