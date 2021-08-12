class Solution {
public:
    // Time: O(M + N). IDEA: Merge from backwards.
    void merge(vector<int>& A, int m, vector<int>& B, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j >= 0)
        {
            if(i >= 0 && A[i] > B[j])
                A[k--] = A[i--];

            else
                A[k--] = B[j--];
        }
    }
    
    // Time: O(min(M, N) * NlogN)
//     void merge(vector<int>& A, int m, vector<int>& B, int n)
//     {
//         int i = 0;
//         int j = 0;
//         while(i < m && j < n)
//         {
//             if(A[i] < B[j]) ++i;
//             else if(A[i] > B[j])
//             {
//                 swap(A[i], B[j]);
//                 sort(B.begin(), B.end());
//                 ++i;
//             }
//             else if(A[i] == B[j])
//                 ++i;
//         }

//         while(j < n)
//         {
//             A[i + j] = B[j];
//             ++j;
//         }
//     }
};