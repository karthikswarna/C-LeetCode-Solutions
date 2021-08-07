class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        vector<int> V;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                V.push_back(matrix[i][j]);
            }
        }
        
        sort(V.begin(), V.end());
        
        return V.at(k-1);
    }
};