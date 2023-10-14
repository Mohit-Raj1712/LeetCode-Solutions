class Trie {
private:
    class TrieNode {
    public:
    vector<TrieNode*> children;
    bool flag;
    
    TrieNode() {
        
        this -> flag = false;
        
        for (int i = 0; i < 26; i++)
            children.push_back(nullptr);
        }
    };

    TrieNode* root;
    
public:
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        
        int l = word.length();
        TrieNode* Node = root;
        transform(word.begin(), word.end(), word.begin(), :: tolower);
        
        for (int i = 0; i < l; i++)
        {
            char c = word[i];
            if (Node -> children[c - 'a'] == nullptr)
                Node -> children[c - 'a'] = new TrieNode();
            
            Node = Node -> children[c - 'a'];
        }
        
        Node -> flag = true;
    }
    
    bool search(string word) {
        
        int l = word.length();
        transform(word.begin(), word.end(), word.begin(), :: tolower);
        
        TrieNode* Node = root;
        
        for (int i = 0; i < l; i++)
        {
            char c = word[i];
            if (Node -> children[c - 'a'] == nullptr)
                return false;
            
            Node = Node -> children[c - 'a'];
        }
        
        return Node -> flag;
    }
    
    bool startsWith(string prefix) {
      
        int l = prefix.length();
        transform(prefix.begin(), prefix.end(), prefix.begin(), :: tolower);
        
        TrieNode* Node = root;
        
        for (int i = 0; i < l; i++)
        {
            char c = prefix[i];
            
            if (Node -> children[c - 'a'] == nullptr)
                return false;
            
            Node = Node -> children[c - 'a'];
        }
        
        return true;
        
    }
};