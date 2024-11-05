class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string str, int k) {
        int windowStart = 0, maxLength = 0;
        int curLength = 0;
        map<char, int> seen;
        
        if (k == 0) return 0;

        for (int i = 0; i < str.size(); i++) {
          
          if (seen.count(str[i]) > 0) {
            seen[str[i]] += 1;
          } else {
            while (seen.size() >= k) {
              seen[str[windowStart]] -= 1;

              if (seen[str[windowStart]] == 0) {
                seen.erase(str[windowStart]);
              }
              windowStart++;
              curLength--;
            }

            seen[str[i]] = 1;
          }

          curLength++;

          if (curLength > maxLength) maxLength = curLength;
          
        }
        return maxLength;
    }
};