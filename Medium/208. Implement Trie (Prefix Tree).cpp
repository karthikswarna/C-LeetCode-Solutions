class TrieNode
{
    TrieNode* charPtrs[26];
    int count;

public:
    TrieNode()
    {
        count = 0;
        for(int i = 0; i < 26; ++i)
            charPtrs[i] = NULL;
    }
    
    friend class Trie;
};

class Trie
{
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* curr = root;
        for(auto ch: word)
        {
            if(curr->charPtrs[ch - 'a'] == NULL)
                curr->charPtrs[ch - 'a'] = new TrieNode();
            
            curr = curr->charPtrs[ch - 'a'];
        }
        
        ++(curr->count);
    }
    
    bool search(string word)
    {
        TrieNode* curr = root;
        for(auto ch: word)
        {
            if(curr->charPtrs[ch - 'a'] == NULL)
                return false;
            
            curr = curr->charPtrs[ch - 'a'];
        }

        return (curr->count > 0);
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* curr = root;
        for(auto ch: prefix)
        {
            if(curr->charPtrs[ch - 'a'] == NULL)
                return false;

            curr = curr->charPtrs[ch - 'a'];
        }
        
        if(curr->count > 0) return true;

        for(int i = 0; i < 26; ++i)
            if(curr->charPtrs[i] != NULL) 
                return true;
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */