class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> ms;
        std::map<int, int> nums;

        for (int i = 0; i < nums1.size(); i++) {
            nums.insert({nums1.at(i), i});
            ans.push_back(-1);
        }

        for (int i = 0; i < nums2.size(); i++) {
            while (!ms.empty() && ms.back() < nums2[i]) {
                if (nums.count(ms.back()) > 0) {
                    ans.at(nums[ms.back()]) = nums2[i];
                }
                ms.pop_back();
            }

            ms.push_back(nums2[i]);
        }
        
        return ans;
    }
};