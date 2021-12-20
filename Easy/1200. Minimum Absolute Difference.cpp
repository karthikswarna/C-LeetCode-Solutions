class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        int minDiff = INT_MAX;

        for(int i = 1; i < arr.size(); ++i)
        {
            int currDiff = abs(arr[i] - arr[i - 1]);
            
            if(currDiff < minDiff)
            {
                result.clear();
                result.push_back( {arr[i - 1], arr[i]} );
                minDiff = currDiff;
            }
            else if(currDiff == minDiff)
                result.push_back( {arr[i - 1], arr[i]} );
        }

        return result;
    }
};