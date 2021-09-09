class Solution {
public:
    // See: https://leetcode.com/problems/container-with-most-water/discuss/200246/Proof-by-formula
    // Time: O(N)
    int maxArea(vector<int>& height)
    {
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i < j)
        {
            int area = (j - i) * std::min(height[i], height[j]);
            max = std::max(area, max);
            
            if(height[i] < height[j]) ++i;      // For the given j, we need to find a larger i
            else --j;
        }
        
        return max;
    }

    // Time: O(N^2)
//     int maxArea(vector<int>& height)
//     {
//         int max = 0;
//         for(int i = 0; i < height.size(); ++i)
//         {
//             for(int j = i + 1; j < height.size(); ++j)
//             {
//                 int area = (j - i) * std::min(height[i], height[j]);
//                 max = std::max(area, max);
//             }
//         }
        
//         return max;
//     }
};