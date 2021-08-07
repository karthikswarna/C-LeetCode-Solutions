class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> V;
        grayCodeUtil(n, V);
        return V;
    }
    
    void grayCodeUtil(int n, vector<int> &V)
    {
        if(n == 1)
        {
            V.push_back(0);
            V.push_back(1);
        }
        else
        {
            grayCodeUtil(n - 1, V);

            int mask = pow(2, n-1);
            int size = V.size();
            for(int i = size - 1; i >= 0; i--)
                V.push_back(mask | V.at(i));
        }
    }
};