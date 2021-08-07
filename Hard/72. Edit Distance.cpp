class Solution {
public:
    int minDistance(string w1, string w2)
    {
        int m = w1.size();
        int n = w2.size();

        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= m; i++)
            table[i][0] = i;

        for(int j = 0; j <= n; j++)
            table[0][j] = j;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(w1[i - 1] == w2[j - 1])
                    table[i][j] = table[i - 1][j - 1];
                else
                    table[i][j] = std::min(table[i - 1][j - 1], std::min(table[i - 1][j], table[i][j - 1])) + 1;
            }
        }

     
        return table[m][n];
    }
};