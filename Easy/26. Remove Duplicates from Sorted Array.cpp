class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
//         if(nums.size() == 0 || nums.size() == 1)
//             return nums.size();

//         int len = 1;
//         int curr_element = nums.at(0);
//         for(int i = 1; i < nums.size(); i++)
//         {
//             if(nums.at(i) != curr_element)
//             {
//                 nums.at(len) = nums.at(i);
//                 len++;
//                 curr_element = nums.at(i);
//             }
//         }
        
//         return len;
        auto it = unique(nums.begin(), nums.end());
        return it - nums.begin();
    }
};