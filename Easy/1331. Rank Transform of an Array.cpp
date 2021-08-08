class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        // Map stores elements in sorted order.
        map<int, int> M;
        for(auto &i : arr)
            if(M.find(i) == M.end())
                M.insert(make_pair(i, 0));
        
        // Assign ranks incrementally.
        int rank = 0;
        for(auto &pair: M)
            M[pair.first] = ++rank;

        // Rank-Transform the array.
        for(auto &i: arr)
            i = M[i];
        
        return arr;
    }
};