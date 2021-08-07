class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        if(rowIndex == 0)
            return vector<int>(1, 1);
        if(rowIndex == 1)
            return vector<int>(2, 1);
        
        vector<int> row(rowIndex + 1, 1);
        vector<int> prevRow = getRow(rowIndex - 1);
        for(int i = 1; i < rowIndex; i++)
            row[i] = prevRow[i] + prevRow[i - 1];
            
        return row;
    }
};