class Solution
{
    int m;
    int n;
public:
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        
        int startX;
        int startY;
        int emptySquares = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1) 
                {
                    startX = i;
                    startY = j;
                }
                
                if(grid[i][j] == 0) ++emptySquares;
            }
        }
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(startX, startY, grid, visited, emptySquares);
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int numRemainingNodes)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == -1) 
            return 0;

        if(grid[i][j] == 2)
            return (numRemainingNodes == 0) ? 1 : 0;

        if(grid[i][j] == 0) 
            --numRemainingNodes;

        visited[i][j] = true;

        int count = 0;
        count += dfs(i + 1, j, grid, visited, numRemainingNodes);
        count += dfs(i - 1, j, grid, visited, numRemainingNodes);
        count += dfs(i, j + 1, grid, visited, numRemainingNodes);
        count += dfs(i, j - 1, grid, visited, numRemainingNodes);

        visited[i][j] = false;

        return count;
    }
};