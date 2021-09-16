class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr)
    {
        int len = arr.size();
        
        if(len == 1) return 1;

        int currLen = (arr[0] == arr[1]) ? 1 : 2;
        int maxLen = currLen;
        bool prevSign = (arr[0] < arr[1]) ? false : true; // true - greater, false - smaller
        
        for(int i = 1; i < len - 1; ++i)
        {
            if(prevSign && (arr[i] < arr[i + 1]))
            {
                prevSign = false;
                ++currLen;
            }
            else if(!prevSign && arr[i] > arr[i + 1])
            {
                prevSign = true;
                ++currLen;
            }
            else
                currLen = (arr[i] == arr[i + 1]) ? 1 : 2;

            maxLen = std::max(currLen, maxLen);
        }

        return maxLen;
    }
};