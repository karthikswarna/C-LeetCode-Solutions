class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int N = temperatures.size();

        stack<int> S;           // Stack of indices.
        vector<int> result(N, 0);
        S.push(0);
        for(int i = 1; i < N; ++i)
        {
            // If current temp is greater than previous.
            if(temperatures[i] > temperatures[S.top()])
            {
                while(!S.empty() && temperatures[i] > temperatures[S.top()])
                {
                    result[S.top()] = i - S.top();
                    S.pop();
                }
            }

            S.push(i);
        }
        
        return result;
    }
};