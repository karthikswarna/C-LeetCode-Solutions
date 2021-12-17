class Solution {
public:
    int minCostToMoveChips(vector<int>& position)
    {
        // An even position can be reached by any other even position with a 0 cost (+/- 2).
        // An odd position can be reached by any other odd position with a 0 cost (+/- 2).
        // All even positions can be clustered at position 2, and all odd positions can be clustered at 1.
        // Answer = min(num of even positions, num of odd positions).
        
        int even = 0;
        int odd = 0;
        for(auto pos: position)
        {
            if(pos % 2 == 0) ++even;
            else ++odd;
        }
        
        return min(odd, even);
    }
};