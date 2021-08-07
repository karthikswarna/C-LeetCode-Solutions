class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
    {
        int m = A.size();
        int n = B.size();

        int i = 0;
        int j = 0;
        int combinedIdx = -1;
        int prevElement;
        int currElement;
        // This traversal technique is similar to the linked list traversal.
        while( (combinedIdx < (m + n)/2) && (i < m) && (j < n))
        {
            if(A[i] == B[j])
            {
                prevElement = currElement;
                currElement = A[i];

                ++i;
                ++combinedIdx;

                // If current element is sufficient for median, we can break;
                if(combinedIdx == (m + n)/2) break;

                prevElement = currElement;
                currElement = B[j];

                ++j;
                ++combinedIdx;
            }
            
            else if(A[i] < B[j])
            {
                prevElement = currElement;
                currElement = A[i];

                ++i;
                ++combinedIdx;
            }

            else
            {
                prevElement = currElement;
                currElement = B[j];

                ++j;
                ++combinedIdx;
            }
        }
        
        // In case one array is ended while finding median, we need to traverse other array till we find the median.
        if(i == m)
            while(combinedIdx < (m + n)/2)
            {
                prevElement = currElement;
                currElement = B[j];

                ++j;
                ++combinedIdx;
            }

        else if(j == n)
            while(combinedIdx < (m + n)/2)
            {
                prevElement = currElement;
                currElement = A[i];

                ++i;
                ++combinedIdx;
            }
        

        // If total length is odd, currElement is the median. Else, its the average. 
        if((m + n) % 2 != 0)
            return currElement;

        return float(prevElement + currElement) / 2;
    }
};