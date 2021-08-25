class Solution {
public:
    int mySqrt(int x)
    {
        if(x < 2) return x;

        int low = 1;
        int high = x;
        int mid, root;

        while(low <= high)
        {
            mid = low + ((high - low) / 2);
            
            if(x / mid == mid) return mid;

            else if(x / mid > mid) 
            {
                low = mid + 1;

                // As we need to find a number whose square is less than or equal to x (and as close to x as possible.)
                root = mid;
            }

            else high = mid - 1;
        }
        
        return root;
    }
};