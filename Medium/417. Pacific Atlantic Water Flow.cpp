class Solution
{
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        m = heights.size();
        n = heights[0].size();
        if(m == 1 && n == 1) return {{0, 0}};

        vector<vector<int>> result;
        vector<bool> canReachPacific(m*n, false); // i * n + j
        vector<bool> canReachAtlantic(m*n, false);

        // Base case for Pacific (Directly connected regions.)
        for(int i = 0; i < m; ++i)
        {
            canReachPacific[i * n] = true;
            canReachAtlantic[i * n + n - 1] = true;
        }

        // Base case for Atlantic (Directly connected regions.)
        for(int j = 0; j < n; ++j)
        {
            canReachPacific[j] = true;
            canReachAtlantic[(m - 1) * n + j] = true;
        }

        findReachableLands(heights, canReachPacific);
        findReachableLands(heights, canReachAtlantic);

        // Find the Islands that can reach both atlantic and pacific.
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(canReachPacific[i * n + j] && canReachAtlantic[i * n + j])
                    result.push_back({i, j});

        return result;
    }
    
    // Given the ocean and the regions directly connected to it, find other regions that can reach ocean.
    void findReachableLands(vector<vector<int>>& heights, vector<bool>& reachableLands)
    {
        queue<int> Q;
        for(int i = 0; i < m*n; ++i)
            if(reachableLands[i]) 
                Q.push(i);
        
        while(!Q.empty())
        {
            int r = Q.front() / n;
            int c = Q.front() % n;
            Q.pop();
            
            reachableLands[r * n + c] = true;       // Also acts as the "visited" set.

            if((r + 1 < m) && (!reachableLands[(r + 1) * n + c]) && (heights[r + 1][c] >= heights[r][c]))
                Q.push((r + 1) * n + c);
            
            if((r - 1 >= 0) && (!reachableLands[(r - 1) * n + c]) && (heights[r - 1][c] >= heights[r][c]))
                Q.push((r - 1) * n + c);
            
            if((c + 1 < n) && (!reachableLands[r * n + (c + 1)]) && (heights[r][c + 1] >= heights[r][c]))
                Q.push(r * n + (c + 1));
            
            if((c - 1 >= 0) && (!reachableLands[r * n + (c - 1)]) && (heights[r][c - 1] >= heights[r][c]))
                Q.push(r * n + (c - 1));
        }
    }
};