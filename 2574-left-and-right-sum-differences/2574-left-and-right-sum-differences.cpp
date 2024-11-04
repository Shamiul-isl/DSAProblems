class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> differenceArray(n);

        int total = 0;

        for (int nums: nums) {
            total += nums;
        }

        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            differenceArray[i] = abs(left - (total - left - nums[i]));
            left += nums[i];
        }
        return differenceArray;
    }
};