class Solution {
public:
    // Simplified Solution
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // Sort intervals by the start value.
        sort(intervals.begin(), intervals.end());
        

        vector<vector<int>> result;
        for(auto interval: intervals)
        {
            if(!result.empty() && interval[0] <= result.back()[1])
                result.back()[1] = std::max(interval[1], result.back()[1]);
            
            else
                result.push_back(interval);
        }
        
        return result;
    }

    // My Original Solution
//     vector<vector<int>> merge(vector<vector<int>>& intervals)
//     {
//         // Sort intervals by the start value.
//         sort(intervals.begin(), intervals.end());

//         vector<vector<int>> result;
//         while(result != intervals)
//         {
//             if(!result.empty())
//                 intervals = result;

//             result.clear();
//             int i = 0;
//             while(i < intervals.size())
//             {
//                 if(i < intervals.size() - 1 && intervals[i + 1][0] <= intervals[i][1])
//                 {
//                     result.push_back(vector<int>{ min(intervals[i][0], intervals[i + 1][0]), 
//                                                   max(intervals[i][1], intervals[i + 1][1]) });
//                     i += 2;
//                 }
//                 else
//                 {
//                     result.push_back(intervals[i]);
//                     ++i;
//                 }
//             }
//         }
        
//         return result;
//     }
};