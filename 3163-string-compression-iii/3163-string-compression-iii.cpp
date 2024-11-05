class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int cur = 1;
        char last = word[0];
        
        for (int i = 1; i < word.size(); i++) {
            if (last != word[i] || cur == 9) {
                res += to_string(cur);
                res += last;
                cur = 1;
                last = word[i];
            } else {
                cur += 1;
            }
            
        }
        
        res += to_string(cur);
        res += last;
        
        return res;
    }
};