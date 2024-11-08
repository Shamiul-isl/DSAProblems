class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int target) {
        int result = 0;

        for (int i = 0; i < arr.size(); i++) {
          vector<int> cur = {arr[i]};
          if (arr[i] < target) result++;
          int curProd = arr[i];
          for (int j = i + 1; j < arr.size(); j++) {
            if (curProd * arr[j] < target) {
              curProd *= arr[j];
              result++;
            } else {
              break;
            }
          }
        }
        // TODO: Write your code here
        return result;
    }
};