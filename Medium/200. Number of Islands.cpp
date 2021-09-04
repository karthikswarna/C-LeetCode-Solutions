class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> visited(m*n, false);

        int count = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(explore(grid, i, j, visited)) count += 1;
    
        return count;
    }
    
    // DFS
    bool explore(vector<vector<char>>& grid, int i, int j, vector<bool>& visited)
    {
        // Bound checks
        bool rowInbounds = 0 <= i && i < grid.size();
        bool colInbounds = 0 <= j && j < grid[0].size();
        if(!rowInbounds || !colInbounds) return false;
        
        // We don't need wotah.
        if(grid[i][j] == '0') return false;

        // If already visited, don't bother
        if(visited[i * grid[0].size() + j]) return false;
        visited[i * grid[0].size() + j] = true;
        
        explore(grid, i - 1, j, visited);
        explore(grid, i + 1, j, visited);
        explore(grid, i, j - 1, visited);
        explore(grid, i, j + 1, visited);
    
        // True to sybolize that we have explored a new island.
        return true;
    }
};