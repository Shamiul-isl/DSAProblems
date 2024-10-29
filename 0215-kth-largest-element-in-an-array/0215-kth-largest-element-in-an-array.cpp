class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> res(nums.begin(), nums.begin() + k);
        make_heap(res.begin(), res.end(), greater());

        for (int i = k; i < nums.size(); i++) {
          if (nums[i] > res.front()) {
            pop_heap(res.begin(), res.end(), greater());
            res.pop_back();
            res.push_back(nums[i]);
            push_heap(res.begin(), res.end(), greater());
          }
        }
        return res.front();
    }
};