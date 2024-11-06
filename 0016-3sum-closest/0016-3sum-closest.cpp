class Solution {
public:
    int threeSumClosest(vector<int>& arr, int targetSum) {
        int closest = NULL;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
          int start = i+1, end = arr.size() - 1;
          while (start < end) {
            int curSum = arr[i] + arr[start] + arr[end];
            int diff = abs(curSum - targetSum);
            if (closest == NULL) {
              closest = curSum;
              if (curSum > targetSum)
                end--;
              else
                start++;
            } else {
              int closeDiff = abs(closest - targetSum);
              if (diff == closeDiff) {
                closest = min(closest, curSum);
              } else if (diff < closeDiff) {
                closest = curSum;
              }
              
              if (curSum > targetSum)
                end--;
              else
                start++;  
                
            }
              
            if (closest == targetSum) return closest;

          }
        }
        return closest;
    }
};