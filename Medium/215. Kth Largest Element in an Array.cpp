class Solution {
public:
    // Using QuickSelect
    int findKthLargest(vector<int>& nums, int k)
    {
        int N = nums.size();
        quickselect(nums, 0, N - 1, N - k);
        
        return nums[N - k];
    }
    
    void quickselect(vector<int>& nums, int left, int right, int k)
    {
        int pivot_index = left + rand() % (right - left + 1);
        
        pivot_index = partition(nums, left, right, pivot_index);
    
        if(pivot_index == k)
            return;
        else if(pivot_index < k)
            quickselect(nums, pivot_index + 1, right, k);
        else
            quickselect(nums, left, pivot_index - 1, k);
    }
    
    int partition(vector<int>& nums, int left, int right, int pivot_index)
    {
        int pivot_element = nums[pivot_index];

        // Place the pivot_element in the end.
        swap(nums[pivot_index], nums[right]);
        
        // Partition the elements into two sets of [< pivot] and [> pivot].
        int len = left;
        for(int i = left; i < right; ++i)
        {
            if(nums[i] < pivot_element)
            {
                swap(nums[i], nums[len]);
                ++len;
            }
        }
        
        // Place the pivot element in the correct position.
        swap(nums[right], nums[len]);
        
        return len;
    }

    // Using Heap
//     int findKthLargest(vector<int>& nums, int k)
//     {
//         priority_queue<int> Q;
//         for(auto &i: nums)
//             Q.push(i);
        
//         while(k > 1)
//         {
//             Q.pop();
//             --k;
//         }

//         return Q.top();
//     }
};