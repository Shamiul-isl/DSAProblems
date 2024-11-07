class Solution {
public:
    int threeSumSmaller(vector<int>& arr, int target) {
        int count = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
          for (int start = i + 1; start < arr.size() - 1; start++) {
            int end = start + 1;

            while (end < arr.size()) {
              int cur = arr[i] + arr[start] + arr[end];
              if (cur >= target)
                  break;
              count++; 
              end++;
            }
          }

        }
        return count;
    }
};