class Solution {
public:
    int maxScore(vector<int>& p, int k)
    {
        int len = p.size();
        int windowSize = len - k;
        int runningSum = 0;
        int minSum = INT_MAX;
        int low, high;

        for(int i = 0; i < len; i++)
        {
            runningSum += p[i];

            if(i >= windowSize - 1)
            {
                if(runningSum < minSum)
                {
                    low = i - windowSize + 1;
                    high = i;
                    minSum = runningSum;
                }
                
                runningSum -= p[i - windowSize + 1];
            }
        }
        
        int ans = 0;
        for(int i = 0; i < low; i++)
            ans += p[i];
        for(int i = high + 1; i < len; i++)
            ans += p[i];
        
        return ans;
    }
};