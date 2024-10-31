class TrieNode {
public:
    TrieNode* children[26]; // Array of pointers for each alphabet character
    bool isEnd; // Flag to mark if a node represents the end of a word

    // Constructor initializes all children to nullptr and isEnd to false
    TrieNode() {
        isEnd = false;
        for (auto &child : children) {
            child = nullptr;
        }
    }
};

// class Solution {
// public:
//     vector<vector<int>> indexPairs(const string& text, const vector<string>& words) {
//         vector<vector<int>> result; // To store the resulting index pairs
//         TrieNode* root = new TrieNode();
        
//         for (int i = 0; i < words.size(); i++) {
//             TrieNode* cur = root;
//             for (char c: words[i]) {
//                 if (!cur->children[c - 'a']) {
//                     cur->children[c - 'a'] = new TrieNode();
//                 }

//                 cur = cur->children[c - 'a'];
//             }
//             cur->isEnd = true;
//         }

//         int start = 0;
//         int end = 0;
//         TrieNode* cur = root;
//         for (int i = 0; i < text.size(); i++) {
//             // cout << text[i] << " " << cur->children[text[i] - 'a'] << " " << root->children[text[i] - 'a'] << endl;
//             char c = text[i] - 'a';
//             if (cur->children[c] != nullptr) {
//                 if (cur->children[text[i] - 'a']->isEnd) {
//                     end = i;
//                     // cout << start << "," << end << endl;
//                     result.push_back(vector<int> {start, end});
//                     // start = i+1;
//                     // cur = root;
//                 } 
//                 // else {
//                 //     cur = cur->children[text[i] - 'a'];
//                 // }
//                 cur = cur->children[text[i] - 'a'];
//             } else if (root->children[text[i-1] - 'a'] && root->children[text[i-1] - 'a']->children[text[i] - 'a']) {
//                 cur = root->children[text[i-1] - 'a']->children[text[i] - 'a'];
//                 start = i-1;
//                 if (cur->isEnd) {
//                     end = i;
//                     // cout << start << "," << end << endl;
//                     result.push_back(vector<int> {start, end});
//                 }

//             } else {
//                 if (root->children[text[i] - 'a']) {
//                     cur = root->children[text[i] - 'a'];
//                     start = i;
//                 } else {
//                     cur = root;
//                     start = i+1;
//                 }
//             }
//         }


//         return result;
//     }
// };


class Trie {
public:
    TrieNode* root; // Root node of the trie

    // Constructor initializes the root node
    Trie() : root(new TrieNode()) {}

    // Inserts a word into the trie
    void insert(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode(); // Create a new node if it doesn't exist
            }
            cur = cur->children[c - 'a']; // Move to the next node
        }
        cur->isEnd = true; // Mark the end of the word
    }
};

// Solution class containing the method to find index pairs
class Solution {
public:
    vector<vector<int>> indexPairs(const string& text, const vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word); // Insert words into the trie
        }

        vector<vector<int>> result; // To store the resulting index pairs
        for (int i = 0; i < text.size(); i++) {
            TrieNode* p = trie.root;
            for (int j = i; j < text.size(); j++) {
                if (p->children[text[j] - 'a'] == nullptr) break; // Break if character is not in trie
                p = p->children[text[j] - 'a'];
                if (p->isEnd) result.push_back({i, j}); // Add index pair if end of word is reached
            }
        }
        return result;
    }
};
