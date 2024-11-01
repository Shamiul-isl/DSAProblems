class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missingNumbers;
        
        for (int i = 0; i < nums.size(); i++) {
          while(nums[i] != i+1 && nums[nums[i] - 1] != nums[i]) {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
          }
        }

        for (int i = 0; i < nums.size(); i++) {
          if (nums[i] != i+1) {
            missingNumbers.push_back(i+1);
          }
        }
        return missingNumbers;
    }
};