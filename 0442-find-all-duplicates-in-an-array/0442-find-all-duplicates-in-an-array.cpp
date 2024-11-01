class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dups;
        set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
          while (nums[i] != i + 1) {
            if (nums[nums[i] - 1] == nums[i]) {
                if (seen.count(nums[i]) == 0) {
                    dups.push_back(nums[i]);
                    seen.insert(nums[i]);
                }
                break;
            }
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
          }
        }
        // sort(dups.begin(), dups.end());
        return dups;
    }
};