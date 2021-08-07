class Solution {
public:
    int getMaximumGenerated(int n)
    {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int max = INT_MIN;
        vector<int> V(n+1);
        V[0] = 0;
        V[1] = 1;

        for(int i = 2; i < n + 1; i++)
        {
            if(i % 2 == 0)
                V[i] = V.at(i / 2);
            else
                V[i] = V.at(i/2) + V.at(i/2 + 1);
            
            
            if(V.at(i) > max)
                max = V.at(i);
        }
        
        return max;
    }
};