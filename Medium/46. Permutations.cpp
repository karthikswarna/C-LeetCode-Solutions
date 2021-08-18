class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        do
        {
            result.push_back(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));
        
        return result;
    }

    // Normal Backtracking solution
//     vector<vector<int>> permute(vector<int>& nums, int cur = 0)
//     {
//         vector<vector<int>> result;

//         if(cur == nums.size() - 1)
//         {
//             for(auto i: nums)
//                 result.push_back(vector<int>{i});
//         }
//         else
//         {
//             vector<vector<int>> tempResult = permute(nums, cur + 1);
//             for(auto i: nums)
//             {
//                 for(auto j : tempResult)
//                 {
//                     if(find(j.begin(), j.end(), i) == j.end())
//                     {
//                         vector<int> newArr = j;
//                         newArr.push_back(i);
//                         result.push_back(newArr);
//                     }
//                 }
//             }
//         }
        
//         return result;
//     }
};