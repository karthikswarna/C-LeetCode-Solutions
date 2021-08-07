class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if(nums.size() == 0)
            return 0;
        
        
        int i = 0, j = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums.at(j) != val)
            {
                nums.at(i) = nums.at(j);
                i++;
            }
        }
        
        return i;
    }
};