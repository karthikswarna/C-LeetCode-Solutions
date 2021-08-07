class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k)
    {
        int len = arr.size();
        vector<int> maxWindow(len - k + 1);
        int idx = -1;
        
        // Store indices of elements in Q.
        deque<int> Q;
        for(int i = 0; i < arr.size(); i++)
        {
            // If already present elements are smaller than current element, they can never be the maximum. So pop them.
            while(!Q.empty() && arr[Q.back()] <= arr[i]) 
                Q.pop_back();
            Q.push_back(i);
            
            // Due to these type of insertions, the deque will be in decreasing order.
            // So the front element in max in the current window.
            if(i >= k - 1)
            {
                maxWindow[++idx] = arr[Q.front()];
    
                // Remove the first element so that the window can be progressed.
                if(Q.front() == i - k + 1) Q.pop_front();
            }
        }
        
        return maxWindow;
    }
};