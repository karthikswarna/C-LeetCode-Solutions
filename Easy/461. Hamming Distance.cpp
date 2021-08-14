class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int hDist = 0;

        // Find ith bit in x and y using AND operation with 1 and then check for equality.
        for(int i = 0; i < 32; ++i)
            if( ((1 << i) & x) != ((1 << i) & y) )
                ++hDist;
    
        return hDist;
    }
};