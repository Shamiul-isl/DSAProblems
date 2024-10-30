class Solution {
public:
  vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.emplace_back();

    for (int i = 0; i < nums.size(); i++) {
      vector<int> tmp{nums[i]};
      subsets.push_back(tmp);


      int curSize = subsets.size();
      for (int j = 1; j < curSize - 1; j++) {
        vector<int> curCopy = subsets[j];
        curCopy.push_back(nums[i]);
        subsets.push_back(curCopy);
      }
    }

    return subsets;
  }
};