class RandomizedSet
{
    unordered_set<int> S;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        return S.insert(val).second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        // the return value of S.erase(val) is the number of elements removed.
        return S.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        auto it = std::next(S.begin(), rand() % S.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */