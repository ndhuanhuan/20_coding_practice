struct TrieNode {
    int count = 0; 
    bool isWord = false;
    TrieNode* children[26] = { nullptr };
};

class Trie {    
private:
    TrieNode* root;
    
    int dfs(TrieNode* node) {
        if (node == nullptr) return 0; 
        
        int res = 0;
        
        if (node->isWord) res += node->count; 
        
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) res += dfs(node->children[i]);
        }
        
        return res;
    };
    
    TrieNode* findWord(string word) {
        TrieNode* node = root; 
        
        for (const auto& c : word) {
            if (node->children[c - 'a'] == nullptr) return nullptr;
      
            node = node->children[c - 'a'];
        }
        
        return node;
    }
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for (const auto& c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode(); 
            }
            
            node = node->children[c - 'a'];
        }
        node->count++; node->isWord = true;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node = findWord(word); 
        
        if (node == nullptr || !node->isWord) return 0;
        
        return node->count;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* node = findWord(prefix);
        
        return dfs(node);
    }
    
    void erase(string word) {
        TrieNode* node = findWord(word);
        
        if (node == nullptr) return;
        
        if (--node->count == 0) node->isWord = false;
    }
};
