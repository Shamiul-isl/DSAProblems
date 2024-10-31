class TrieNode {
    public:
        TrieNode* children[26] = {nullptr};
        bool wordEnd = false;
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            
            cur = cur->children[i];
        }
        
        cur->wordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            
            cur = cur->children[i];
        }
        return cur->wordEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c: prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            
            cur = cur->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */