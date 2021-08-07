class Solution {
public:
    // Better Solution. The condition max(left) <= min(right) should be satisfied.
    int partitionDisjoint(vector<int>& a)
    {
        int maxInLeft = a[0];
        int max = a[0];
        int ans = 0;
        for(int i = 1; i < a.size(); i++)
        {
            if(a[i] < maxInLeft)
            {
                ans = i;
                maxInLeft = max;
            }
            
            max = std::max(a[i], max);
        }

        return ans + 1;
    }
};