class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int end = static_cast<int>(nums.size()) - 1;
        while (i <= end) {
            if (nums[i] == val) {
                nums[i] = nums[end];
                --end;
            } else {
                ++i;
            }
        }
        return i;
    }
};