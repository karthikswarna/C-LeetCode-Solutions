class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold)
    {
        threshold *= k;
        int runningSum = 0;
        int count = 0;

        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {
            runningSum += arr[windowEnd];
            
            if(windowEnd >= k - 1)
            {
                if(runningSum >= threshold)
                    count++;
                runningSum -= arr[windowEnd - k + 1];
            }
        }
        
        return count;
    }
};