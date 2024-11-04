class Solution {
public:
    vector<int> calculatePrefixSum(vector<int>& nums) {
        vector<int> prefix(nums.size());

        prefix[0] = nums[0];

        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }

        return prefix;
    }

    int calculateRangeSum(vector<int>& prefix, int i, int j) {
        if (j < 0 || i >= prefix.size())
            return 0;
        else if (i == 0) 
            return prefix[j]; 
        else
            return prefix[j] - prefix[i-1];
    }

    int findMiddleIndex(vector<int>& nums) {
        // ToDo: Write Your Code Here.

        vector<int> prefix = calculatePrefixSum(nums);

        for (int i = 0; i < nums.size(); i++) {
            int left, right;
            left = calculateRangeSum(prefix, 0, i - 1);
            right = calculateRangeSum(prefix, i+1, nums.size() - 1);

            if ((i == 0 && right == 0) || (i == nums.size() - 1 && left == 0) || (left == right)) 
                return i;
        }

        return -1; 
    }
};