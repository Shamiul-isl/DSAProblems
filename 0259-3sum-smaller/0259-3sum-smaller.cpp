class Solution {
public:
    int threeSumSmaller(vector<int>& arr, int target) {
        int count = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
          for (int start = i + 1; start < arr.size() - 1; start++) {
            int end = arr.size() - 1;
            if (arr[i] + arr[start] + arr[start + 1] > target) {
                continue;
            }
            while (start < end) {
              int cur = arr[i] + arr[start] + arr[end];
              if (cur < target) count++;
              end--;
            }
          }

        }
        return count;
    }
};