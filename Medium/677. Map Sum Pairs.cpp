class MapSum
{
    unordered_map<string, int> M;
public:
    MapSum()
    {
        
    }
    
    void insert(string key, int val)
    {
        M[key] = val;
    }
    
    int sum(string prefix)
    {
        int sum = 0;
        for_each(M.begin(), M.end(), 
                 [&sum, &prefix](auto pair)
                 {
                    auto res = mismatch(prefix.begin(), prefix.end(), pair.first.begin());
                    if (res.first == prefix.end())
                        sum += pair.second;
                 });
            
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */