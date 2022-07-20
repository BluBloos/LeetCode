class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry >= 1) {
                digits[i] += carry;
                carry = 0;
                if (digits[i] > 9) {
                    carry = digits[i] - 9;
                    digits[i] = digits[i] % 10;
                }   
            } else {
                break;
            }
        }
        // check MSB
        if (carry >= 1) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
        
    }
};