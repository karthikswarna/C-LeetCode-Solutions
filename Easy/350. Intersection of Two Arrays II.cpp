class Solution {
public:
    // Sorting and finding intersection.
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> intersection;
        // Using STL function.
        // set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(intersection));
        
        // Custom implementation
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j]) ++i;
            else if(nums1[i] > nums2[j]) ++j;
            else
            {
                intersection.push_back(nums1[i]);
                ++i; ++j;
            }
        }
        
        return intersection;
    }

    // Using Hash Table.
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
//     {
//         unordered_map<int, int> M;
//         for(auto i: nums1)
//             ++M[i];
        
//         vector<int> intersection;
//         for(auto i: nums2)
//         {
//             if(M[i] > 0)
//             {
//                 intersection.push_back(i);
//                 --M[i];
//             }
//         }
        
//         return intersection;
//     }
};