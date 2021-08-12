// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        return findFirstBadVersion(1, n);
    }
    
    int findFirstBadVersion(int low, int high)
    {
        if(low == high) return low;

        int mid = low + (high - low) / 2;
        
        if(isBadVersion(mid))
            return findFirstBadVersion(low, mid);
        
        return findFirstBadVersion(mid + 1, high);
    }
};