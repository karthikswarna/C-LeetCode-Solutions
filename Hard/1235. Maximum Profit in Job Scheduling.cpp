class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int N = startTime.size();

        vector<vector<int>> jobs(N);
        for(int i = 0; i < N; ++i)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){ return a[0] < b[0]; });
        
        vector<int> memo(N, -1);
        return getMaxProfit(jobs, memo, 0);
    }

    int getMaxProfit(vector<vector<int>>& jobs, vector<int>& memo, int curr)
    {
        if(curr >= jobs.size()) return 0;
        if(memo[curr] != -1) return memo[curr];

        // We can either include the current job, or exclude the current job.
        // If included, the next job should not be overlapping with the current one.
        int nextIndex;
        for(int i = curr + 1; i < jobs.size(); ++i)
            if(jobs[curr][1] <= jobs[i][0])
            {
                nextIndex = i;
                break;
            }
        
        int includeProfit = jobs[curr][2] + getMaxProfit(jobs, memo, nextIndex);

        // Dont include current job, and proceed to next.
        int excludeProfit = getMaxProfit(jobs, memo, curr + 1);

        return memo[curr] = max(includeProfit, excludeProfit);
    }
};