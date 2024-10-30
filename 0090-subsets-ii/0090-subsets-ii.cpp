class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> subsets;
    std::set<vector<int>> seen;

    subsets.push_back(vector<int>());

    for (int i = 0; i < nums.size(); i++) {
      vector<int> tmp{nums[i]};
      int curSize = subsets.size();
      
      if (!seen.contains(tmp)) {
        subsets.push_back(tmp);
        seen.insert(tmp);
      }

      
      for (int j = 1; j < curSize; j++) {
        vector<int> curCopy = subsets[j];
        curCopy.push_back(nums[i]);
        sort(curCopy.begin(), curCopy.end());
        if (!seen.contains(curCopy)) {

          subsets.push_back(curCopy);
          seen.insert(curCopy);
        }
      }
    }

    return subsets;
  }
};