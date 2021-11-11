class Solution
{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int N = nums.size();
        vector<pair<int, int>> V(N);
        for(int i = 0; i < N; ++i)
            V[i] = make_pair(nums[i], i);
        
        vector<int> count(N, 0);
        mergeSort(V, count, 0, N - 1);

        return count;
    }

    // Merge Sort in "DESCENDING ORDER". This is important as we are finding "SMALLER ELEMENTS" to the right.
    void mergeSort(vector<pair<int, int>>& arr, vector<int>& count, int low, int high)
    {
        if(low >= high) return;

        int mid = low + (high - low) / 2;
        mergeSort(arr, count, low, mid);
        mergeSort(arr, count, mid + 1, high);
        
        merge(arr, count, low, mid, mid + 1, high);
    }

    void merge(vector<pair<int, int>>& arr, vector<int>& count, int low1, int high1, int low2, int high2)
    {
        vector<pair<int, int>> merged(high2 - low1 + 1);
        int i = low1;
        int j = low2;
        int combinedIdx = 0;
        while(i <= high1 && j <= high2)
        {
            if(arr[i].first <= arr[j].first)
                merged[combinedIdx++] = arr[j++];
            
            else    // arr[i].first > arr[j].first
            {
                // This below line is the only one that calculates "count". Rest is just merge sort.
                count[arr[i].second] += high2 - j + 1;
                merged[combinedIdx++] = arr[i++];
            }
        }
        
        while(i <= high1)
            merged[combinedIdx++] = arr[i++];

        while(j <= high2)
            merged[combinedIdx++] = arr[j++];

        // Merge the actual array.
        for(i = 0; i <= high2 - low1; ++i)
            arr[i + low1] = merged[i];
    }
};