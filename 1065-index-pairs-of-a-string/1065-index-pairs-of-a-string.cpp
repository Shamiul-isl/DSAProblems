class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEnd = false; 
};

class Solution {
public:
    vector<vector<int>> indexPairs(const string& text, const vector<string>& words) {
        vector<vector<int>> result; // To store the resulting index pairs
        TrieNode* root = new TrieNode();
        
        for (int i = 0; i < words.size(); i++) {
            TrieNode* cur = root;
            for (char c: words[i]) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }

                cur = cur->children[c - 'a'];
            }
            cur->isEnd = true;
        }

        int end;
        
        for (int j = 0; j < text.size(); j++) {
            TrieNode* cur = root;
            for (int i = j; i < text.size(); i++) {
                if (cur->children[text[i] - 'a']) {
                    if (cur->children[text[i] - 'a']->isEnd) {
                        end = i;
                        result.push_back(vector<int> {j, end});
                    } 
                    cur = cur->children[text[i] - 'a'];
                } else {
                    break;
                }
            }
        }


        return result;
    }
};

