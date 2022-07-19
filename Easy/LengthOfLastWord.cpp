class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordLen = 0;
        // Go backwards through the string.
        int i = s.size() - 1;
        while ( i >= 0 ) {
            if (s[i] != ' ') {
                wordLen++;
            } else if ( wordLen > 0 ) {
                break;
            }   
            i--;
        }
        return wordLen;
    }
};