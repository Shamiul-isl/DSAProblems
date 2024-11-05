class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int maxLength = 0;
        int windowStart = 0;
        int currLength = 0;
        unordered_map<int, int> seen;

        for (int i = 0; i < arr.size(); i++) {
            if (seen.count(arr[i]) > 0) {
                seen[arr[i]] += 1;
            } else {
                while (seen.size() >= 2) {
                    seen[arr[windowStart]] -= 1;

                    if (seen[arr[windowStart]] == 0) seen.erase(arr[windowStart]);

                    windowStart++;
                    currLength--;
                }

                seen[arr[i]] = 1;
            }

            currLength++;

            maxLength = max(currLength, maxLength);
        }
        
        return maxLength;
    }
};