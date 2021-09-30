class Solution
{
    int n;
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        n = isConnected.size();
        int count = 0;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(isConnected[i][j] == 1)
                {
                    isConnected[i][i] = 0;
                    dfs(isConnected, i, j);
                    count += 1;
                }
            }
        }
    
        return count;
    }
    
    void dfs(vector<vector<int>>& isConnected, int i, int j)
    {
        // Marks the node as visited.
        isConnected[j][j] = 0;

        // Marks the edge as visited.
        isConnected[i][j] = 0;
        isConnected[j][i] = 0;

        for(int k = 0; k < n; ++k)
        {
            if(k != j && isConnected[j][k] == 1)
                dfs(isConnected, j, k);
        }
    }
};