class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int aI = a.size() - 1;
        int bI = b.size() - 1;
        bool _c = false;
        while (true) {
            if (aI < 0 && bI < 0) break;
            bool _a = (aI >= 0) ? a[aI--] == '1' : false;
            bool _b = (bI >= 0) ? b[bI--] == '1' : false;
            // NOTE: This is going to be the slow method.
            result += (_c ^ (_a ^ _b)) ? '1' : '0';
            _c = (_a && _b) || ( _c && (_a ^ _b) );
        }
        if (_c) {
            result += '1';
        }
        reverse(result.begin(), result.end()); // Maybe this works ?
        return result;
    }
};