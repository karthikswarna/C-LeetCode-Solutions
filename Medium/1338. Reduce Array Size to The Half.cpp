class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }
    
    int minSetSize(vector<int>& arr)
    {
        int len = arr.size();
        unordered_map<int, int> M;
        for(int i = 0; i < len; i++)
        {
            if(M.find(arr.at(i)) != M.end())
                M[arr.at(i)] += 1;
            else
               M[arr.at(i)] = 1;
        }
        
        vector<pair<int, int> > A;
        for (auto& it : M)
            A.push_back(it);
        sort(A.begin(), A.end(), cmp);
        
        len /= 2;
        int i = 0;
        for(; i < A.size(); i++)
        {
            len = len - A.at(i).second;
            if(len <= 0) break;
        }
               
        return i + 1;
    }
};