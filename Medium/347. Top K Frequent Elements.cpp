class Solution
{
private:
    unordered_map<int, int> M;
    vector<int> unique;

public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // (Number -> frequency) mapping
        for(auto &i: nums)
            ++M[i];
        
        // Array of all the unique elements from nums.
        for(const auto &pair: M)
            unique.push_back(pair.first);

        int N = unique.size();
        vector<int> topKFrequentElements(k);
        quickselect(0, N - 1, N - k); // kth most frequent element is (N-k)th element from the start.
cout << 'x';
        copy(unique.begin() + N - k, unique.end(), topKFrequentElements.begin());

        return topKFrequentElements;
    }
    
    void quickselect(int left, int right, int k)
    {
        if(left == right) return;
        
        // Randomly select a pivot element.
        int pivot_index = left + rand() % (right - left + 1);
        
        // partition the array with pivot_index'th element as pivot
        pivot_index = partition(left, right, pivot_index);
        
        // Based on the position of pivot in the array, recurse.
        if(pivot_index == k)
            return;
        else if(pivot_index < k)
            quickselect(pivot_index + 1, right, k);
        else
            quickselect(left, pivot_index - 1, k);
        cout << 'c';

    }
    
    int partition(int left, int right, int pivot_index)
    {
        int pivot_frequency = M[unique[pivot_index]];
        
        // Place the pivot element in the end of the array.
        swap(unique[pivot_index], unique[right]);
        
        // Partition all the elements as per their frequency w.r.t the frequency of the pivot element.
        int len = left;
        for(int i = left; i <= right; ++i)
        {
            if(M[unique[i]] < pivot_frequency)
            {
                swap(unique[i], unique[len]);
                ++len;
            }
        }
        
        // Move the pivot into its position in the middle.
        swap(unique[right], unique[len]);
        
        return len;
    }
};