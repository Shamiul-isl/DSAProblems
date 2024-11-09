class Solution {
public:
    void sortColors(vector<int>& arr) {
        vector<int> colors = {0,1,2};
        int start = 0, end = start + 1;
        for (int i = 0; i < colors.size(); i++) {
          end = start + 1;
          while (start != arr.size() - 1) {
            if (arr[start] != colors[i] && arr[end] == colors[i]) {
              int temp = arr[start];
              arr[start] = arr[end];
              arr[end] = temp;
              start++;
            } else if (arr[start] == colors[i]) {
              start++;
            }
            end++;

            if (end == arr.size()) break;
          }
        }
        // return arr;
    }
};