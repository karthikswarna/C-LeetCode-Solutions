class Solution
{
    int m, n;
    int bestPathHP = INT_MIN;
public:
    // Algorithm for recursive implementation:
    // 1. Consider all the paths to reach from end from the start. 
    // 2. For each of the path, consider the cell for which the HP is minimum (say minHP) along that path. To travel along that path, (-minHP + 1) is the minimum health needed.
    // 3. So we can calculate the minimum health needed to travel along all the possible paths and return the minimum of all such values.
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();

        // Recursive implementation. 
        // minHealthAchieved(dungeon, 0, 0, 0, INT_MAX);    
        // return 1 - min(bestPathHP, 0);
        
        // Iterative implementation.
        // hp[i][j] is the minimum hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
        hp[m - 1][n] = 1;
        hp[m][n - 1] = 1;
        
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                hp[i][j] = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                
    // if the hp needed to move from prev position to (i,j) is negative, 1 hp is sufficient. 
                if(hp[i][j] <= 0) hp[i][j] = 1;
            }
        }
        
        return hp[0][0];
    }
    
    int minHealthAchieved(vector<vector<int>>& dungeon, int i, int j, int currHP, int minHPSoFar)
    {
        if(i >= m || j >= n) return INT_MAX;

        currHP += dungeon[i][j];
        minHPSoFar = min(currHP, minHPSoFar);

        if(i == m - 1 && j == n - 1) 
        {
            bestPathHP = max(bestPathHP, minHPSoFar);
            return minHPSoFar;
        }

        return min(minHealthAchieved(dungeon, i + 1, j, currHP, minHPSoFar), 
                   minHealthAchieved(dungeon, i, j + 1, currHP, minHPSoFar));
    }
};