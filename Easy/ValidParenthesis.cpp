class Solution {
    char _c = '0';
    char parStack[10000];
    int parStackLen = 0;
public:
    inline 
    const char &getEnd() {
        if (parStackLen == 0) return _c;
        return parStack[parStackLen - 1];
    }
    bool isValid(string s) {
        for (char c : s) {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    parStack[parStackLen++] = c;
                    break;
                case ')':
                    if (getEnd() == '(') {
                        parStackLen--;
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (getEnd() == '[') {
                        parStackLen--;
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (getEnd() == '{') {
                        parStackLen--;
                    } else {
                        return false;
                    }
                    break;
            }  
        }
        return parStackLen == 0;
    }
};