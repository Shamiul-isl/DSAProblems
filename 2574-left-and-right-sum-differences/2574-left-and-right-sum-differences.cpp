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
            int rightSum = total - left - nums[i];
            differenceArray[i] = abs(left - rightSum);
            left += nums[i];
        }
        // TODO: Write your code here
        return differenceArray;
    }
};