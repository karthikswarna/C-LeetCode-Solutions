class Solution {
public:
    // Solution using Deque.
//     vector<int> maxSlidingWindow(vector<int>& arr, int k)
//     {
//         int len = arr.size();
//         vector<int> maxWindow(len - k + 1);
//         int idx = -1;
        
//         // Store indices of elements in Q.
//         deque<int> Q;
//         for(int i = 0; i < arr.size(); i++)
//         {
//             // If already present elements are smaller than current element, they can never be the maximum. So pop them.
//             while(!Q.empty() && arr[Q.back()] <= arr[i]) 
//                 Q.pop_back();
//             Q.push_back(i);
            
//             // Due to these type of insertions, the deque will be in decreasing order.
//             // So the front element in max in the current window.
//             if(i >= k - 1)
//             {
//                 maxWindow[++idx] = arr[Q.front()];
    
//                 // Remove the first element so that the window can be progressed.
//                 if(Q.front() == i - k + 1) Q.pop_front();
//             }
//         }
        
//         return maxWindow;
//     }
    
    // My Solution using Priority Queue
    vector<int> maxSlidingWindow(vector<int>& arr, int k)
    {
        int len = arr.size();
        vector<int> maxWindow(len - k + 1);
        int idx = -1;
        
        auto comp = [](pair<int, int> a, pair<int, int> b){ return a.first < b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> Q(comp);

        for(int i = 0; i < arr.size(); i++)
        {
            Q.push(make_pair(arr[i], i));
            
            if(i >= k - 1)
            {
                // Remove elements that are outside of the current window (outdated elements.)
                while(!Q.empty() && Q.top().second < i - k + 1) 
                    Q.pop();

                maxWindow[++idx] = Q.top().first;
            }
        }
        
        return maxWindow;
    }
};