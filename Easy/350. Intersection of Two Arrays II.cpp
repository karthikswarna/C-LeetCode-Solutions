class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;

        array<int, 1001> A = {0};
        for(auto &i : nums1)
            ++A[i];
        
        for(auto &i: nums2)
        {
            if(A[i] > 0) ans.push_back(i);
            
            --A[i];
        }
            
        return ans;
    }
};