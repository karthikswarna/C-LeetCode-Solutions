class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = -1;
        int xMin = 1;
        int yMin = 0;
        int xMax = m - 1;
        int yMax = n - 1;
        int xChanging = 0;
        int yChanging = 1;

        vector<int> result(m*n, 0);
        int curr = 0;

        while(curr < m*n)
        {
            if(yChanging != 0)  // y is changing
            {
                j += yChanging;
                result[curr++] = matrix[i][j];
                
                if(j == yMax && yChanging == 1)
                {
                    xChanging = yChanging;
                    yChanging = 0;
                    --yMax;
                }
                else if(j == yMin && yChanging == -1)
                {
                    xChanging = yChanging;
                    yChanging = 0;
                    ++yMin;
                }
            }
            else if(xChanging != 0) // x is changing
            {
                i += xChanging;
                result[curr++] = matrix[i][j];
                
                if(i == xMax && xChanging == 1)
                {
                    yChanging = -xChanging;
                    xChanging = 0;
                    --xMax;
                }
                else if(i == xMin && xChanging == -1)
                {
                    yChanging = -xChanging;
                    xChanging = 0;
                    ++xMin;
                }
            }
        }
        
        return result;
    }
};