class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int shiftBack = 0;
        int k = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (shiftBack > 0) {
                nums[i-shiftBack] = nums[i];
            }
            int _val = nums[i];
            if (_val == val) {
                // found duplicate.
                shiftBack++;
                k--;
            }
        }
        return k;
    }
};