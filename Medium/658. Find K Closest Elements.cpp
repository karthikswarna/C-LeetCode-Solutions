class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int len = arr.size();

        vector<int> result(k);
        int filledTill = -1;
        
        vector<int> diff(len);
        int closestIndex = 0;
        int minDiff = INT_MAX;
        
        for(int i = 0; i < len; i++)
        {
            
            diff[i] = abs(arr[i] - x);
            if((diff[i] < minDiff) || ((diff[i] == minDiff) && (arr[i] < arr[closestIndex])))
            {
                minDiff = diff[i];
                closestIndex = i;
            }
        }

        int left = closestIndex;
        int right = closestIndex + 1;
        while(!(filledTill >= k-1))
        {
            if((left >= 0) && (right <= len - 1))
            {
                if((diff[left] < diff[right]) || ((diff[left] == diff[right]) && (arr[left] <= arr[right])))
                {
                    result[++filledTill] = arr[left];
                    left--;
                }
                else if((diff[left] > diff[right]) || ((diff[left] == diff[right]) && (arr[left] > arr[right])))
                {
                    result[++filledTill] = arr[right];
                    right++;
                }
            }
            else if(left < 0)
            {
                result[++filledTill] = arr[right];
                right++;
            }
            else if(right > len - 1)
            {
                result[++filledTill] = arr[left];
                left--;                
            }
        }

        sort(result.begin(), result.end());
        return result;
    }    
};