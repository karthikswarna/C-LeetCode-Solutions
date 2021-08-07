class KthLargest {
    int k;
    multiset<int> S;
public:
    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        for(auto i : nums)
            this->S.insert(i);
    }
    
    int add(int val)
    {
        S.insert(val);
        auto it = S.rbegin();
        return *(std::next(it, k - 1));
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */