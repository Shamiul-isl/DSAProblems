class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> triplets;
        set<vector<int>> seen;

        for (int i = 0; i < arr.size(); i++) {
          if (i > 0 && arr[i] == arr[i-1]) {
            continue;
          }
          vector<int> complement = {arr[i]};
          int start = i+1, end = arr.size() - 1;
          int comp = 0 - arr[i];

          while (start < end) {
            int temp = arr[start] + arr[end];
            if (temp == comp) {
              complement.push_back(arr[start]);
              complement.push_back(arr[end]);
              if (seen.count(complement) < 1)
                seen.insert(complement);
              complement = {arr[i]};
              start++;
              end--;
            } else if (temp > comp) {
              end--;
            } else {
              start++;
            }
          }

          if (complement.size() > 1 and seen.count(complement) < 1) {
            seen.insert(complement);
          }

        }

        for (vector<int> trip: seen) triplets.push_back(trip);

        return triplets;
    }
};